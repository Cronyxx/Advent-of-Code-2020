#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <iterator>

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

    for (int i = 0; i < bootCode.size(); i++) 
    {
        if (bootCode[i].command == "jmp")
        {
            bootCode[i].command = "nop";
        } else if (bootCode[i].command == "nop") 
        {
            bootCode[i].command = "jmp";
        }

        int counter = 0;
        int acc = 0;
        bool temp[bootCode.size()];
        memset(temp, false, bootCode.size());

        while (counter != bootCode.size() && temp[counter] == false) 
        {
            temp[counter] = true;
            if (bootCode[counter].command == "acc") 
            {
                acc += bootCode[counter].offset;
            } else if (bootCode[counter].command == "jmp") 
            {
                counter += bootCode[counter].offset;
                continue;
            }
            counter++;
        }

        if (counter == bootCode.size()) 
        {
            std::cout << acc << std::endl;
        }

        if (bootCode[i].command == "jmp")
        {
            bootCode[i].command = "nop";
        } else if (bootCode[i].command == "nop") 
        {
            bootCode[i].command = "jmp";
        }
    }
}