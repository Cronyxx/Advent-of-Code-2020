#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>

int main() 
{
    std::string line;
    std::ifstream file("Seats.txt");
    std::unordered_set<int> seats;

    int max = 0;
    int min = 1023;

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

        int seatNum = row * 8 + col;
        seats.insert(seatNum);
        max = std::max(max, seatNum);
        min = std::min(min, seatNum);
    }

    for (int i = min; i <= max; i++) 
    {
        if (seats.count(i) == 0) 
        {
            std::cout << i << std::endl;
            break;
        }
    }
}