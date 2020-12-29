#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <utility>

int main() 
{
    std::ifstream file("Adapters.txt");
    std::string line;

    std::vector<int> adapters;

    while (getline(file, line)) 
    {
        adapters.push_back(stoi(line));
    }

    std::sort(adapters.begin(), adapters.end());

    std::queue<std::pair<int, long>> queue;
    queue.emplace(std::make_pair(0,0));
    queue.emplace(std::make_pair(0,0));
    queue.emplace(std::make_pair(0,1));

    for (auto adapter : adapters) 
    {
        long result = 0;
        for (int i = 0; i < 3; i++) 
        {
            if (adapter - queue.front().first <= 3) 
            {
                result += queue.front().second;
            }
            queue.push(queue.front());
            queue.pop();
        }

        queue.pop();
        queue.emplace(std::make_pair(adapter, result));
    }
    std::cout << queue.back().second << std::endl;
}