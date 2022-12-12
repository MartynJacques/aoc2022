#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

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

std::vector<int> multiply_these{};

void check_cycle(int cycle, int x)
{
    if (cycle == 20)
        multiply_these.push_back(x * 20);
    if (cycle == 60)
        multiply_these.push_back(x * 60);
    if (cycle == 100)
        multiply_these.push_back(x * 100);
    if (cycle == 140)
        multiply_these.push_back(x * 140);
    if (cycle == 180)
        multiply_these.push_back(x * 180);
    if (cycle == 220)
        multiply_these.push_back(x * 220);
}

int main()
{
    std::string line{};
    std::ifstream input_stream{"input.txt"};

    int cycle = 0;
    int x = 1;
    while (std::getline(input_stream, line))
    {
        if (line == "noop")
        {
            for (int i = 0; i < 1; i++)
            {
                cycle++;
                check_cycle(cycle, x);
            }
        }
        else
        {
            auto line_split = split(line, ' ');
            int increment = stoi(line_split[1]);
            for (int i = 0; i < 2; i++)
            {
                cycle++;
                check_cycle(cycle, x);
            }
            x += increment;
        }

        if (cycle > 220)
            break;
    }

    int result = 0;
    for (int i : multiply_these)
    {
        std::cout << i << std::endl;
        result += i;
    }
    std::cout << result << std::endl;
}