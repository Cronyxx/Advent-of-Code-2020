#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

int main() 
{
    std::ifstream file("Adapters.txt");
    std::string line;

    int volt_diffs[3] = {0, 0, 1};

    std::unordered_set<int> adapters;

    while (getline(file, line)) 
    {
        adapters.insert(stoi(line));
    }

    int counter = 0;
    int currVoltage = 0;

    while (counter < adapters.size()) 
    {
        for (int i = 1; i < 4; i++) 
        {
            if (adapters.count(currVoltage + i) != 0) 
            {
                volt_diffs[i - 1] += 1;
                currVoltage += i;
                break;
            }
        }
        counter++;
    }
    std::cout << volt_diffs[0] * volt_diffs[2] << std::endl;
}