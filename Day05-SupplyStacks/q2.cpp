#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <deque>

using namespace std;

int main () {


    ifstream myFile;
    myFile.open("input.txt");
    string line;

    int linesToRead = 8;
    int charsToRead = 4;
    const int numberOfStacks = 9;
    vector<deque<char>> stacks(numberOfStacks);

    while (linesToRead >= 1)
    {
        getline(myFile, line);

        for (int i = 0; i < numberOfStacks; i++)
        {
            char crate = line.substr(i*charsToRead, charsToRead)[1];

            //Handle white space.
            if ((crate >= 'A') && (crate <='Z'))
            {
                stacks[i].push_front(crate);
            }
                        
        }

        linesToRead--;
    }


    //Skip lines between the crates and statements
    getline(myFile, line);
    getline(myFile, line);

    while (getline(myFile, line))
    {
        std::istringstream iss(line);
        string discard;
        int amount, from, to;
        iss >> discard >> amount >> discard >> from >> discard >> to;
        
        from--;to--;
        int fromStackSize = stacks[from].size();
        for (int i = amount; i >= 1; i--)
        {
            if (!stacks[from].empty())
            {
                
                stacks[to].push_back(stacks[from].at(fromStackSize - i));
            }
        }

        for (int i = 0; i < amount; i++)
        {
            if (!stacks[from].empty())
            {
                stacks[from].pop_back();
            }
            
        }
        
    }
    
    for (int i = 0; i < numberOfStacks; i++)
    {
        cout << stacks[i].back();
    }

    myFile.close();
}