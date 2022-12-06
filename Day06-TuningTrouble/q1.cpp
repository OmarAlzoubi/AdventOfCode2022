#include <fstream>
#include <iostream>
#include <set>

using namespace std;

int main() 
{
    ifstream myFile;
    string input;
    myFile.open("input.txt");
    if (myFile.fail())
    {
        cout << "Could not open the file!\n";
        return 1;
    }
    
    getline(myFile, input);
    int length = input.length();
    int packetLength = 14;

    for (int i = 0; i < length - packetLength; i++)
    {
        set<char> mySet;

        for (int j = i; j < packetLength + i; j++)
        {
            mySet.insert(input[j]);
        }

        if (mySet.size() == packetLength)
        {
            cout << i + packetLength << endl;
            break;
        }
    }

    myFile.close();
    
}