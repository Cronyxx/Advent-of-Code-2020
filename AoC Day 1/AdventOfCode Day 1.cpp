#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

using namespace std;

int main() 
{
    string line;
    unordered_set<int> numbers;
    ifstream myfile ("Number.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            int number = stoi(line);
            numbers.insert(number);
        }
        myfile.close();
    }

    int ans = 0;

    for (auto num : numbers) 
    {
        if (numbers.count(2020 - num) > 0)
        {
            ans = num * (2020 - num);
        }
    }
    cout << ans << endl;
}
