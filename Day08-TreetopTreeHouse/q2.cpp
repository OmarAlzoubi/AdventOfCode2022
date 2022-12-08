#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int checkTree (int currentTree, int treeRow, int treeColumn, int rows, int columns);

vector<vector<int>> trees;


int main ()
{
    ifstream myFile;
    myFile.open("input.txt");
    if (myFile.fail())
    {
        cout << "Could not open the file\n";
        return 1;
    }

    string line;
    int rows = 0, columns = 0;


    while (getline(myFile, line))
    {
        columns = line.length();

        trees.push_back(vector<int>());

        for (int i = 0; i < columns; i++)
        {
            trees[rows].push_back(line[i] - '0');
        }

        rows++;
    }

    myFile.close();

    int scenicScore = 0;

    //No need to skip the boundary this time like in part 1.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            int temp = checkTree(trees[i][j], i, j, rows, columns);

            if (temp > scenicScore)
            {
                scenicScore = temp;
            }
    

        }

    }
    
    cout << scenicScore;
}


int checkTree (int currentTree, int treeRow, int treeColumn, int rows, int columns)
{
    int seeLeft = 0, seeRight = 0, seeUp = 0, seeBottom = 0;
    
    //check left (column)
    //x starts this way because we need to check trees closer to currnt tree first.
    for (int x = treeColumn - 1; x >= 0; x--)
    {
        seeLeft++;
        if (trees[treeRow][treeColumn] <= trees[treeRow][x])
        {
            
            break;
        }

    }


    //check right (column)
    for (int x = treeColumn + 1; x < columns; x++)
    {
        seeRight++;
        if (trees[treeRow][treeColumn] <= trees[treeRow][x])
        {
            break;
        }

    }

    //check up (row)
    for (int y = treeRow - 1; y >= 0; y--)
    {
        seeUp++;
        if (trees[treeRow][treeColumn] <= trees[y][treeColumn])
        {
            break;
        }

    }



    //check down (row)
    for (int y = treeRow + 1; y < rows; y++)
    {
        seeBottom++;
        if (trees[treeRow][treeColumn] <= trees[y][treeColumn])
        {
            break;
        }

    }


    int scenicScore = seeLeft * seeRight * seeUp * seeBottom;

    return scenicScore;
}