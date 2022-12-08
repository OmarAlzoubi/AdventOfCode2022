#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node
{
    public:

        Node(string name, Node* parent, bool isFile, int size)
        {
            this->name = name;
            this->parent = parent;
            this->isFile = isFile;
            this->size = 0;
        }

        string name;
        Node* parent;
        bool isFile;
        int size;
        vector<Node*> subNodes;

        ~Node()
        {
            cout << "Node: " << name <<" Was Deleted" << endl;
        }

};

enum Message{isFile, isDirectory, isCommand};

Message parseLine(string line);
void buildTree(Node* root, vector<string> input);
int traverseTree(Node* root);
void deleteTree (Node* root);

bool compare(int a, int b)
{
    return a <= b;
}

vector<int> dirsSize;

int main()
{
    vector<string> input;
    ifstream myFile;
    myFile.open("input.txt");
    if (myFile.fail())
    {
        cout << "Could not open the file!\n";
        return 1;
    }

    //Read input 
    string line;
    while (getline(myFile, line))
    {
        input.push_back(line);
    }

    myFile.close();

    Node* root = new Node("/", NULL, false, 0);
    buildTree(root, input);
    traverseTree(root);

    //Size of root
    int totalSize = dirsSize.back();
    int totalSpace = 70000000;
    int requiredFreeSpace = 30000000;
    int currentFreeSpace = totalSpace - totalSize;
    int spaceToFree = requiredFreeSpace - currentFreeSpace;

    sort(dirsSize.begin(), dirsSize.end(), compare);
    
    for (int i = 0; i < dirsSize.size(); i++)
    {
        if (dirsSize[i] - spaceToFree > 0)
        {
            cout << dirsSize[i] << endl;
            break;
        }

    }

    deleteTree(root);
    delete root;
}

Message parseLine(string line)
{
    Message msg;
    //Current line is a command
    if (line[0] == '$')
    {
        msg = isCommand;
        return msg;
    }
    //Current line is a directory.
    else if (line.substr(0, line.find(' ')) == "dir")
    {
        msg = isDirectory;
        return msg;
    }
    //Current line is a file
    else
    {
        msg = isFile;
        return msg;
    }
}

void buildTree(Node* root, vector<string> input)
{
    Node* currentDirectory = root;
    for (int i = 2; i < input.size(); i++)
    {
        Message msg = parseLine(input[i]);
        if (msg == isDirectory)
        {
            string directoryName = input[i].substr(input[i].find(' ') + 1);
            Node* newDirectory = new Node(directoryName, currentDirectory, false, 0);
            currentDirectory->subNodes.push_back(newDirectory);
        }
        else if (msg == isFile)
        {
            string fileName = input[i].substr(input[i].find(' ') + 1);
            int fileSize = stoi(input[i].substr(0, input[i].find(' ')));
            Node* newFile = new Node(fileName, currentDirectory, true, 0);
            newFile->size = fileSize;
            currentDirectory->subNodes.push_back(newFile);            
        }
        //Current line is a command
        else
        {
            string command = input[i].substr(2);

            if (command == "ls")
            {
                continue;
            }

            if (command == "cd ..")
            {
                currentDirectory = currentDirectory->parent;
            }
            else
            {
                string directory = command.substr(command.find(" ") + 1);

                for (int i = 0; i < currentDirectory->subNodes.size(); i++)
                {
                    if (currentDirectory->subNodes[i]->name == directory)
                    {
                        currentDirectory = currentDirectory->subNodes[i];
                        break;
                    }
                }
            }
        }

    }    
}

int traverseTree(Node* root)
{
    Node* currentDirectory = root;

    for (int i = 0; i < currentDirectory->subNodes.size(); i++)
    {
        if (currentDirectory->subNodes[i]->isFile)
        {
            currentDirectory->size += currentDirectory->subNodes[i]->size;
        }
        else
        {
            currentDirectory->size += traverseTree(currentDirectory->subNodes[i]);
        }
    }

    dirsSize.push_back(currentDirectory->size);
    return currentDirectory->size;
}

void deleteTree (Node* root)
{
    Node* currentDirectory = root;

    for (int i = 0; i < currentDirectory->subNodes.size(); i++)
    {
        deleteTree(currentDirectory->subNodes[i]);
        delete currentDirectory->subNodes[i];
    }
    
}