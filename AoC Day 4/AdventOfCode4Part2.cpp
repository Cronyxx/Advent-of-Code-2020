#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <regex>
#include <unordered_set>

static std::unordered_set<std::string> eyeColor {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};

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

bool checkInput(std::string& key, std::string& value) 
{
    if (key == "byr")
    {
        if (value.length() == 4) 
        {
            try 
            {
                int intValue = stoi(value);
                return !(intValue < 1920 || intValue > 2002);
            } catch (const std::exception& e)
            {
                return false;
            }
        }
        return false;
    } else if (key == "iyr")
    {
        if (value.length() == 4) 
        {
            try 
            {
                int intValue = stoi(value);
                return !(intValue < 2010 || intValue > 2020);
            } catch (const std::exception& e)
            {
                return false;
            }
        }
        return false;
    } else if (key == "eyr")
    {
        if (value.length() == 4) 
        {
            try 
            {
                int intValue = stoi(value);
                return !(intValue < 2020 || intValue > 2030);
            } catch (const std::exception& e)
            {
                return false;
            }
        }
        return false;
    } else if (key == "hgt")
    {
        if (std::regex_match(value, std::regex("[0-9]+(cm|in)")))
        {
            int number = stoi(value.substr(0, value.length() - 2));
            std::string unit = value.substr(value.length() - 2, 2);

            if (unit == "cm") {
                return !(number < 150 || number > 193);
            } else if (unit == "in")
            {
                return !(number < 59 || number > 76);
            }
        }
        return false;
    } else if (key == "hcl")
    {
        return std::regex_match(value, std::regex("#[0-9a-f]{6}"));
    } else if (key == "ecl")
    {
        return eyeColor.find(value) != eyeColor.end();
    } else if (key == "pid")
    {
        return std::regex_match(value, std::regex("[0-9]{9}"));
    }
    return false;
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
                    std::string value;
                    getline(fieldStream, value);
                    if (checkInput(key, value)) 
                    {
                        isPresent[mapOfIndex[key]] = true;
                    }
                }
            }
        }
        file.close();

        std::cout << numOfValidPassport << std::endl;
    }
}