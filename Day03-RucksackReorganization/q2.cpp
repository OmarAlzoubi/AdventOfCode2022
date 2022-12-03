#include <fstream>
#include <iostream>
#include <map>

const int charsNum = 200;
const int linesInGroup = 3;

bool isUpper(char ch)
{

    return (ch >= 'A') && (ch <='Z'); 
}

int main(){

    std::ifstream myFile;
    myFile.open("input.txt");
    int prioritySum = 0;
    int lowercasePriority = 1;
    int upperCasePriority = 27;

    while (!myFile.eof())
    {

        std::string group[linesInGroup];
        int groupMap[linesInGroup][charsNum] = {};

        for (int i = 0; i < linesInGroup; i++)
        {
            std::string line;
            getline(myFile, line);
            group[i] = line;
        }

        //Mapping
        for (int i = 0; i < linesInGroup; i++)
        {
            std::string line = group[i];

            for (int j = 0; j < line.length(); j++)
            {
                groupMap[i][line[j]]++;
            }
        }

        //Line to compare with.
        std::string line = group[0];
        for (int i = 0; i < group[0].length(); i++)
        {

            if ((groupMap[0][line[i]] > 0) && (groupMap[1][line[i]] > 0) && (groupMap[2][line[i]] > 0))
            {
                char charInBoth = line[i];
                if(isupper(line[i]))
                 {
                    prioritySum = prioritySum + charInBoth - 'A' + upperCasePriority;
                    break;
                 }
                 else
                 {
                    prioritySum = prioritySum + charInBoth - 'a' + lowercasePriority;
                    break;
                 }
            }
        }

    }
    

    std::cout << prioritySum;


}