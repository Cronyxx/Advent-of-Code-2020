#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int getTrees(std::vector<char *> const& map, int numOfRows, int numOfCols, int rightStep, int downStep) 
{
    int r_index = 0;
    int c_index = 0;
    int numOfTrees = 0;

    while (r_index < numOfRows) 
    {
        if (map[r_index][c_index] == '#') 
        {
            numOfTrees++;
        }
        r_index = r_index + downStep;
        c_index = (c_index + rightStep) % numOfCols;
    }
    
    return numOfTrees;
}

int main()
{
    std::vector<char *> map;
    std::string line;
    int numOfRows = 0;
    int numOfCols = 0;
    
    std::ifstream file("Map.txt");
    if (file.is_open())
    {
        while (getline(file, line))
        {
            char* c_string = new char[line.length() + 1];
            std::strcpy(c_string, line.c_str());
            map.push_back(c_string);
            numOfCols = line.length();
            numOfRows++;
        }
    }

    int a = getTrees(map, numOfRows, numOfCols, 1, 1);
    int b = getTrees(map, numOfRows, numOfCols, 3, 1);
    int c = getTrees(map, numOfRows, numOfCols, 5, 1);
    int d = getTrees(map, numOfRows, numOfCols, 7, 1);
    int e = getTrees(map, numOfRows, numOfCols, 1, 2);
    
    std::cout << a* b * c * d * e << std::endl;
}