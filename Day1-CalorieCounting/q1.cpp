#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    ifstream myFile;

    myFile.open("input.txt");
    string line;

    int max = -1;
    int temp = 0;

    int topElfs = 3;
    vector<int> maxVector;

    while(getline(myFile, line)){

        if(line == ""){
            if(temp > max){
                max = temp;
            }

            if (maxVector.size() == topElfs){
                int minIndex = std::distance(std::begin(maxVector), std::min_element(std::begin(maxVector), std::end(maxVector)));
                if (temp > maxVector[minIndex]){
                    maxVector[minIndex] = temp;
                }
            }else{
               maxVector.push_back(temp); 
            }

            temp = 0;
        }else{
            
            temp = temp + stoi(line.c_str());
        }
    }

    int minIndex = std::distance(std::begin(maxVector), std::min_element(std::begin(maxVector), std::end(maxVector)));
    if (temp > maxVector[minIndex]){
        maxVector[minIndex] = temp;
    }
    printf("%d\n",max);
     printf("%d %d %d\n",maxVector[0], maxVector[1], maxVector[2]);

    myFile.close();
}
    