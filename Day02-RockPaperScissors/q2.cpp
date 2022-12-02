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

int roundScore (char me, char opp){

    if (me == 'X')
    {
        if (opp == 'A'){
            return loseScore + shapeScore['C'];
        }
        else if (opp == 'B')
        {
            return loseScore + shapeScore['A'];
        }
        else
        {
            return loseScore + shapeScore['B'];
        }
    }
    else if (me == 'Y')
    {
        if (opp == 'B'){
            return drawScore + shapeScore['B'];
        }
        else if (opp == 'A')
        {
            return drawScore + shapeScore['A'];
        }
        else
        {
            return drawScore + shapeScore['C'];
        }
    }
    else
    {
        if (opp == 'C'){
            return winScore + shapeScore['A'];
        }
        else if (opp == 'B')
        {
            return winScore + shapeScore['C'];
        }
        else
        {
            return winScore + shapeScore['B'];
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

    std::ifstream myFile;
    myFile.open("input.txt");
    std::string line;

    int score = 0;

    while(std::getline(myFile, line)) {

        char opp, me;

        opp = line.c_str()[0];
        me = line.c_str()[2];

        score+= roundScore(me, opp);


    }

    std::cout << score;
}

