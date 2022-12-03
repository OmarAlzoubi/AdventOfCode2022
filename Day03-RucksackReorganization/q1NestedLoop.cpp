#include <fstream>
#include <iostream>
#include <map>

const int charsNum = 26*2;
int main(){

//Loop over a line
//Add every char to map
//If map[CurrentChar] == 2 & index >= len(line)/2
    //get this char
    //and do the priority to calc the score

    std::ifstream myFile;
    myFile.open("input.txt");
    std::string line;
    int prioritySum = 0;
    int lowercasePriority = 1;
    int upperCasePriority = 27;

    while (getline(myFile, line))
    {

        int lineLength = line.length();

        for (int i = 0; i < lineLength/2; i++) {
            for (int j = lineLength/2; j < lineLength; j++) {

                if (line[i] == line[j]) {

                    char charInBoth = line[i];

                    if (charInBoth >= 'A' && charInBoth <= 'Z' ) {
                        prioritySum = prioritySum + charInBoth - 'A' + upperCasePriority;
                        //Force exit the loops
                        i = lineLength;
                        j = lineLength;
                    }
                    else if (charInBoth >= 'a' && charInBoth <= 'z' ) {
                        prioritySum = prioritySum + charInBoth - 'a' + lowercasePriority;
                        //Force exit the loops
                        i = lineLength;
                        j = lineLength;
                    }
                    else{
                        std::cout << "Can't handle this kind of chars";
                        return 1;
                    }
                }
            }
        }

    }
    

    std::cout << prioritySum;


}