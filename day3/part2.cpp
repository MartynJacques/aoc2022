#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <array>
#include <vector>
#include <set>

char find_common(std::vector<std::string> &lines)
{
    std::string int_one;
    std::string int_two;

    std::sort(lines[0].begin(), lines[0].end());
    std::sort(lines[1].begin(), lines[1].end());
    std::sort(lines[2].begin(), lines[2].end());

    std::set_intersection(
        lines[0].begin(), lines[0].end(), lines[1].begin(), lines[1].end(), std::back_inserter(int_one));
    std::set_intersection(
        int_one.begin(), int_one.end(), lines[2].begin(), lines[2].end(), std::back_inserter(int_two));
    return int_two[0];
}

int main()
{
    std::ifstream input_stream{"input.txt"};
    std::string line{};
    std::vector<char> groups{};
    std::vector<std::string> lines{};

    while (std::getline(input_stream, line))
    {
        lines.push_back(line);
        if (lines.size() == 3)
        {
            char common = find_common(lines);
            groups.push_back(common);
            lines.clear();
        }
    }

    int total = 0;
    for (char c : groups)
    {
        if (isupper(c))
        {
            total = total + (c - 'A') + 27;
        }
        else
        {
            total = total + (c - 'a') + 1;
        }
    }
    std::cout << total << std::endl;
}
