#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

struct Instruction 
{
    std::string command;
    int offset;

    Instruction(std::string c, int num) : command(c), offset(num) {}
};

int main() 
{
    std::ifstream file("Assembly.txt");
    std::string line;

    std::vector<Instruction> bootCode;

    while (getline(file, line)) 
    {
        std::smatch match;
        std::regex_match(line, match, std::regex("(\\w+) ([+-])(\\d+)"));
        int offset = stoi(match[3]);
        if (match[2] == "-") 
        {   
            offset = -offset;
        }
        bootCode.emplace_back(match[1], offset);
    }

    bool array[bootCode.size()];
    memset(array, false, bootCode.size());

    int accumulator = 0;
    int counter = 0;

    while (array[counter] == false) 
    {
        array[counter] = true;
        if (bootCode[counter].command == "acc") 
        {
            accumulator += bootCode[counter].offset;
        } else if (bootCode[counter].command == "jmp") 
        {
            counter += bootCode[counter].offset;
            continue;
        }
        counter++;
    }

    std::cout << accumulator << std::endl;
}