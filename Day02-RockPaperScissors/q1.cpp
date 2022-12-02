//Rock = 1  X   A
//Paper = 2 Y   B
//Scissors = 3  Z   C   

//Win = 6
//Draw = 3
//Lose = 0

#include <iostream>
#include <fstream>
#include <map>

const int loseScore = 0;
const int drawScore = 3;
const int winScore = 6;

std::map<char, int> shapeScore;
std::map<char, char> xyz_abc_map;


int roundScore (char me, char opp){

    if (me == 'A')
    {
        if (opp == 'A'){
            return drawScore + shapeScore[me];
        }
        else if (opp == 'B')
        {
            return loseScore + shapeScore[me];
        }
        else
        {
            return winScore + shapeScore[me];
        }
    }
    else if (me == 'B')
    {
        if (opp == 'B'){
            return drawScore + shapeScore[me];
        }
        else if (opp == 'A')
        {
            return winScore + shapeScore[me];
        }
        else
        {
            return loseScore + shapeScore[me];
        }
    }
    else
    {
        if (opp == 'C'){
            return drawScore + shapeScore[me];
        }
        else if (opp == 'B')
        {
            return winScore + shapeScore[me];
        }
        else
        {
            return loseScore + shapeScore[me];
        }
    }
}

int main() {

//Y => Draw
//X => Lose
//Z => Win
    shapeScore['A'] = 1;
    shapeScore['B'] = 2;
    shapeScore['C'] = 3;

    xyz_abc_map['X'] = 'A';
    xyz_abc_map['Y'] = 'B';
    xyz_abc_map['Z'] = 'C';
    

    std::ifstream myFile;
    myFile.open("input.txt");
    std::string line;

    int score = 0;

    while(std::getline(myFile, line)) {

        char opp, me;

        opp = line.c_str()[0];
        me = line.c_str()[2];
        me = xyz_abc_map[me];

        score+= roundScore(me, opp);


    }

    std::cout << score;
}

