#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    std::vector<char *> map;
    std::string line;
    int numOfRows = 0;
    int numOfCol = 0;
    
    std::ifstream file("Map.txt");
    if (file.is_open())
    {
        while (getline(file, line))
        {
            char* c_string = new char[line.length() + 1];
            std::strcpy(c_string, line.c_str());
            map.push_back(c_string);
            numOfCol = line.length();
            numOfRows++;
        }
        file.close();
    }
    

    int r_index = 0;
    int c_index = 0;
    int numOfTrees = 0;

    while (r_index < numOfRows) 
    {
        if (map[r_index][c_index] == '#') 
        {
            numOfTrees++;
        }
        r_index++;
        c_index = (c_index + 3) % numOfCol;
    }
    
    std::cout << numOfTrees << std::endl;
}