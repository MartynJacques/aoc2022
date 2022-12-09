#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <vector>
#include <sstream>

std::vector<std::string> split(const std::string &target, char c)
{
    std::string temp;
    std::stringstream stringstream{target};
    std::vector<std::string> result;

    while (std::getline(stringstream, temp, c))
    {
        result.push_back(temp);
    }

    return result;
}

int main()
{
    std::ifstream input_stream{"input.txt"};
    std::string line{};
    int total = 0;
    while (std::getline(input_stream, line))
    {
        auto ssplit = split(line, '-');
        auto midsplit = split(ssplit[1], ',');

        int start_one = std::stoi(ssplit[0]);
        int end_one = std::stoi(midsplit[0]);

        int start_two = std::stoi(midsplit[1]);
        int end_two = std::stoi(ssplit[2]);

        // std::cout << start_one << ' ' << end_one << ' ' << start_two << ' ' << end_two << std::endl;

        if (!(end_one < start_two || end_two < start_one))
        {
            total++;
        }
    }

    std::cout << total << std::endl;
}