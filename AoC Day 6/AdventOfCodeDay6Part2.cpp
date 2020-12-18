#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() 
{
    std::ifstream file("Forms.txt");
    std::string line;

    int counts = 0;
    std::vector<std::string> strArrayList;

    while (getline(file, line)) 
    {
        if (line.empty())
        {
            std::string result = strArrayList[0];
            std::string temp;
            std::sort(result.begin(), result.end());
            for (int i = 1; i < strArrayList.size(); i++) 
            {
                std::sort(strArrayList[i].begin(), strArrayList[i].end());
                std::set_intersection(result.begin(), result.end(), strArrayList[i].begin(), strArrayList[i].end(), std::back_inserter(temp));
                result = temp;
                temp.clear();
            }
            counts = counts + result.size();
            strArrayList.clear();
            continue;
        }
        strArrayList.push_back(line);
    }
    // Last iteration
    std::string result = strArrayList[0];
    std::string temp;
    std::sort(result.begin(), result.end());
    for (int i = 1; i < strArrayList.size(); i++) 
    {
        std::sort(strArrayList[i].begin(), strArrayList[i].end());
        std::set_intersection(result.begin(), result.end(), strArrayList[i].begin(), strArrayList[i].end(), std::back_inserter(temp));
        result = temp;
    }
    counts = counts + result.size();
    strArrayList.clear();

    std::cout << counts << std::endl;
}