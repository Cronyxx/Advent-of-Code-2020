#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <tuple>
#include <functional>

using namespace std;

tuple <int, int> getRange(string& range) 
{
    // Example input : 3-5 
    stringstream stream(range);
    string number;

    getline(stream, number, '-');
    int a = stoi(number);
    getline(stream, number, '-');
    int b = stoi(number);
    return make_tuple(a, b);
}

int main()
{
    int numOfValid = 0;
    string line;
    
    ifstream file("Password.txt");
    if (file.is_open())
    {
        while (getline(file, line))
        {
            stringstream stream(line);
            string token;

            getline(stream, token, ' ');
            auto[low, high] = getRange(token);

            getline(stream, token, ' ');
            char key = token.c_str()[0];

            getline(stream, token, ' ');
            unsigned int occurances = count(token.begin(), token.end(), key);

            if (occurances >= low && occurances <= high) 
            {
                numOfValid++;
            }
        }
        file.close();
    }
    cout << numOfValid << endl;
}

