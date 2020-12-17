#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

void initialiseMap(std::unordered_map<std::string, int>& mapOfIndex, std::vector<std::string>& keyList) {
    for (int i = 0; i < keyList.size(); i++) 
    {
        mapOfIndex.insert(std::make_pair(keyList[i], i));
    }
}

bool checkValid(bool array[], int size)  
{
    for (int i = 0; i < size; i++) 
    {
        if (!array[i]) {
            return false;
        }
    }
    return true;
}

int main() 
{
    std::string line;
    std::ifstream file("Passports.txt");
    std::unordered_map<std::string, int> mapOfIndex;
    std::vector<std::string> keyList {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};

    initialiseMap(mapOfIndex, keyList);

    if (file.is_open())
    {
        int arrSize = 7;
        bool isPresent[arrSize];

        int numOfValidPassport = 0;

        while (getline(file, line))
        {
            if (line.empty()) 
            {   
                if (checkValid(isPresent, arrSize)) 
                {
                    numOfValidPassport++;
                }   

                // Reset variables
                for (int i = 0; i < arrSize; i++) 
                {
                    isPresent[i] = false;
                }
                continue;
            }

            std::stringstream lineStream(line);
            std::string fields; 
            while (getline(lineStream, fields, ' ')) 
            {
                std::stringstream fieldStream(fields);
                std::string key;

                getline(fieldStream, key, ':');
                if (mapOfIndex.find(key) != mapOfIndex.end()) 
                {
                    isPresent[mapOfIndex[key]] = true;
                }
            }
        }
        file.close();

        std::cout << numOfValidPassport << std::endl;
    }
}