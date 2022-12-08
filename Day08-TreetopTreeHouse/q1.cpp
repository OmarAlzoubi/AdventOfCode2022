#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

bool checkTree (int currentTree, int treeRow, int treeColumn, int rows, int columns);

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

    int numberOfVisibleTrees = 2 * (rows + columns) - 4;

    //Skip the boundary by starting from 1 and ending in rows/columns - 1
    for (int i = 1; i < rows - 1; i++)
    {
        for (int j = 1; j < columns - 1; j++)
        {
            int current = trees[i][j];
            if (checkTree(trees[i][j], i, j, rows, columns))
            {
                numberOfVisibleTrees++;
            }
            
        }

    }
    
    cout << numberOfVisibleTrees;
}


bool checkTree (int currentTree, int treeRow, int treeColumn, int rows, int columns)
{
    bool visibleLeft = true, visibleRight = true, visibleUp = true, visibleBottom = true;
    //check left (column)
    for (int x = 0; x < treeColumn; x++)
    {
        if (trees[treeRow][treeColumn] <= trees[treeRow][x])
        {
            visibleLeft = false;
            break;
        }

    }

    if (visibleLeft) 
    {
        return true;
    }

    //check right (column)
    for (int x = treeColumn + 1; x < columns; x++)
    {
        if (trees[treeRow][treeColumn] <= trees[treeRow][x])
        {
            visibleRight = false;
            break;
        }

    }

    if (visibleRight) 
    {
        return true;
    }

    //check up (row)
    for (int y = 0; y < treeRow; y++)
    {
        if (trees[treeRow][treeColumn] <= trees[y][treeColumn])
        {
            visibleUp = false;
            break;
        }

    }

    if (visibleUp) 
    {
        return true;
    }

    //check down (row)
    for (int y = treeRow + 1; y < rows; y++)
    {
        if (trees[treeRow][treeColumn] <= trees[y][treeColumn])
        {
            visibleBottom = false;
            break;
        }

    }

    if (visibleBottom) 
    {
        return true;
    }

    return false;
}