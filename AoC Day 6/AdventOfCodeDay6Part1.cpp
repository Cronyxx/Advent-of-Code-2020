#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

int main() 
{
    std::ifstream file("Forms.txt");
    std::string line;

    int counts = 0;
    std::unordered_set<char> charSet;
    std::string charStream;

    while (getline(file, line)) 
    {
        if (line.empty())
        {
            for (auto it = charStream.cbegin(); it != charStream.cend(); ++it) 
            {
                if (!charSet.count(*it)) 
                {
                    charSet.insert(*it);
                    counts++;
                }
            }
            charSet.clear();
            charStream.clear();
            continue;
        }
        charStream.append(line);
    }

    // Last iteration
    for (auto it = charStream.cbegin(); it != charStream.cend(); ++it) 
    {
        if (!charSet.count(*it)) 
        {
            charSet.insert(*it);
            counts++;
        }
    }

    std::cout << counts << std::endl;
}