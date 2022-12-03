#include <fstream>
#include <iostream>
#include <map>

const int charsNum = 200;
bool isUpper(char ch)
{

    return (ch >= 'A') && (ch <='Z'); 
}

int main(){

    std::ifstream myFile;
    myFile.open("input.txt");
    std::string line;
    int prioritySum = 0;
    int lowercasePriority = 1;
    int upperCasePriority = 27;



    while (getline(myFile, line))
    {
        int leftMap[charsNum] = {};
        int rightMap[charsNum] = {};
        int lineLength = line.length();

        for (int i = 0; i < lineLength; i++)
        {

            if (i < lineLength/2)
            {
                leftMap[line[i]]++;
            }
            else
            {

                rightMap[line[i]]++;
            }
        }

        for (int i = 0; i < lineLength/2; i++)
        {

            if (((leftMap[line[i]] > 0) && (rightMap[line[i]] > 0)))
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