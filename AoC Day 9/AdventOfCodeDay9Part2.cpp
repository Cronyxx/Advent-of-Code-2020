#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() 
{
    std::ifstream file("Encodings.txt");
    std::string line;

    std::vector<long> encodings;
    long invalidNum;

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
            invalidNum = encodings[i];
            break;
        }
        found = false;
    }

    int start = 0;
    int end = 1;
    int sum = encodings[start];
    while (end < encodings.size()) {
        if (sum < invalidNum) {
            sum += encodings[end];
            end++;
        } else if (sum > invalidNum) 
        {
            sum -= encodings[start];
            start++;
        } else 
        {
            long min = invalidNum;
            long max = 0;
            for (int i = start; i < end; i++) 
            {
                min = min > encodings[i] ? min = encodings[i] : min;
                max = max < encodings[i] ? max = encodings[i] : max;
            }
            std::cout << min + max << std::endl;
            break;
        }
    }
}