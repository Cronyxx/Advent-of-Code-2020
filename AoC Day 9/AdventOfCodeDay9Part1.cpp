#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() 
{
    std::ifstream file("Encodings.txt");
    std::string line;

    std::vector<long> encodings;

    while (getline(file, line)) 
    {
        encodings.push_back(stol(line));
    }

    bool found = false;

    for (int i = 25; i < encodings.size(); i++) 
    {
        for (int j = 1; j < 25 && !found; j++) 
        {
            for (int k = j + 1; k < 26; k++) 
            {
                if (encodings[i - j] + encodings[i - k] == encodings[i]) {
                    found = true;
                    break;
                }
            }
        }
        if (!found) 
        {
            std::cout << encodings[i] << std::endl;
            break;
        }
        found = false;
    }
}