#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <regex>

struct Bag 
{
    std::string colour;
    int weight;

    Bag (std::string s, int w) : colour(s), weight(w) {}
};

int dfs(std::unordered_map<std::string, std::vector<Bag>>& map, std::string currBag) 
{
    int result = 1;
    if (map.count(currBag) != 0) 
    {
        for (auto bag : map[currBag]) 
        {
            result += dfs(map, bag.colour) * bag.weight;
        }
    }
    return result;
}

int main() 
{
    std::ifstream file("Rules.txt");
    std::string line;
    
    std::unordered_map<std::string, std::vector<Bag>> map;

    while (getline(file, line)) 
    {
        std::smatch match;
        std::regex_search(line, match, std::regex("(.*)(?: bags contain )"));

        std::string src;
        src = match[1];
        
        map.emplace(match[1], std::vector<Bag>());

        while (std::regex_search(line, match, std::regex("(\\d) (\\w+ (\\w+)?) bag[s]?"))) 
        {
            map[src].emplace_back(match[2].str(), stoi(match[1]));
            line = match.suffix().str();
        } 
    }

    int result = dfs(map, "shiny gold");

    std::cout << result - 1 << std::endl;
}