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
            auto[index1, index2] = getRange(token);

            getline(stream, token, ' ');
            char key = token.c_str()[0];

            getline(stream, token, ' ');

            bool condition1 = token[index1 - 1] == key;
            bool condition2 = token[index2 - 1] == key;

            if ((condition1 && !condition2) || (!condition1 && condition2)) 
            {
                numOfValid++;
            }
        }
    }
    cout << numOfValid << endl;
}

