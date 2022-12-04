#include <fstream>
#include <iostream>



int main()
{

    std::ifstream myFile;
    myFile.open("input.txt");
    std::string line;

    int result = 0;

    while(getline(myFile, line))
    {
        std::string p1 = line.substr(0, line.find(','));
        std::string p2 = line.substr(line.find(',') + 1);

        int p1Start = stoi(p1.substr(0, '-'));
        int p1End = stoi(p1.substr(p1.find('-') + 1));

        int p2Start = stoi(p2.substr(0, '-'));
        int p2End = stoi(p2.substr(p2.find('-') + 1));

        if (((p1Start <= p2Start) && (p1End >= p2End)) || ((p2Start <= p1Start) && (p2End >= p1End)))
        {
            result++;
        }
    }

    std::cout << result;


}