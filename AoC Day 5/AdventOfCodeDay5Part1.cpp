#include <iostream>
#include <string>
#include <fstream>

int main() 
{
    std::string line;
    std::ifstream file("Seats.txt");

    int max = 0;

    while (getline(file, line)) 
    {
        int low = 0;
        int high = 127;

        int row;
        int col;

        char locations[11];
        strcpy(locations, line.c_str());

        for (int i = 0; i < 7; i++) 
        {
            int range = high - low + 1;
            if (locations[i] == 'F')
            {
                high = high - range / 2;
            } else if (locations[i] == 'B') 
            {
                low = low + range / 2;
            } else 
            {
                std::cout << "Error" << std::endl;
            }
        }

        row = low;

        low = 0;
        high = 7;

        for (int i = 7; i < 10; i++) 
        {
            int range = high - low + 1;
            if (locations[i] == 'L')
            {
                high = high - range / 2;
            } else if (locations[i] == 'R') 
            {
                low = low + range / 2;
            } else 
            {
                std::cout << "Error" << std::endl;
            }
        }

        col = low;
        max = std::max(max, row * 8 + col);
    }

    std::cout << max << std::endl;
}