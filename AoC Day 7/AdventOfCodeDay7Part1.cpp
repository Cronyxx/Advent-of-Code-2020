#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <regex>
#include <unordered_set>
#include <queue>

int main() 
{
    std::ifstream file("Rules.txt");
    std::string line;
    
    std::unordered_map<std::string, std::vector<std::string>> map;

    while (getline(file, line)) 
    {
        std::smatch match;
        std::regex_search(line, match, std::regex("(.*)(?: bags contain )"));

        std::string dest;
        dest = match[1];

        while (std::regex_search(line, match, std::regex("\\d (\\w+ (\\w+)?) bag[s]?"))) 
        {
            map.emplace(match[1], std::vector<std::string>());
            map[match[1]].push_back(dest);
            line = match.suffix().str();
        } 
    }
    std::queue<std::string> queue;
    std::unordered_set<std::string> set;

    queue.push("shiny gold");
    while (!queue.empty())
    {
        std::string current = queue.front();
        queue.pop();

        if (set.count(current) == 0) 
        {
            set.insert(current);
            for (auto element : map[current]) 
            {
                queue.push(element);
            }
        }
    }

    std::cout << set.size() - 1 << std::endl;
}