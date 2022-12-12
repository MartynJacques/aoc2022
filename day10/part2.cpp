#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <utility>

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

std::pair<int, int> to_coords(int x)
{
    int i = x / 40;
    int j = x % 40;
    return {i, j};
}

void draw(int x, int cursor, std::vector<std::vector<char>> &display)
{
    auto x_pair = to_coords(x);
    auto cursor_pair = to_coords(cursor);

    // check left
    if (cursor_pair.second == x_pair.second - 1)
    {
        display[cursor_pair.first][cursor_pair.second] = '#';
        return;
    }

    // check mid
    if (cursor_pair.second == x_pair.second)
    {
        display[cursor_pair.first][cursor_pair.second] = '#';
        return;
    }

    // check right
    if (cursor_pair.second == x_pair.second + 1)
    {
        display[cursor_pair.first][cursor_pair.second] = '#';
        return;
    }
}

void print_display(std::vector<std::vector<char>> &display)
{
    for (auto v1 : display)
    {
        for (auto v2 : v1)
        {
            std::cout << v2;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    std::string line{};
    std::ifstream input_stream{"input.txt"};

    std::vector<std::vector<char>> display(6, std::vector<char>(40, '.'));

    int cycle = 0;
    int x = 1;
    while (std::getline(input_stream, line))
    {
        if (line == "noop")
        {
            for (int i = 0; i < 1; i++)
            {
                draw(x, cycle, display);
                cycle++;
            }
        }
        else
        {
            auto line_split = split(line, ' ');
            int increment = stoi(line_split[1]);
            for (int i = 0; i < 2; i++)
            {
                draw(x, cycle, display);
                cycle++;
            }
            x += increment;
        }

        if (cycle > 240)
            break;
    }
    print_display(display);
}