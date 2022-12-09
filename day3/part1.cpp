#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <vector>

int main()
{
    std::ifstream input_stream{"input.txt"};
    std::string line{};
    std::vector<char> dups{};
    while (std::getline(input_stream, line))
    {
        bool seen[122] = {false};
        int line_len = line.size();
        int half_line_len = line_len / 2;

        for (int i = 0; i < half_line_len; i++)
        {
            seen[line.at(i) - 'A'] = true;
        }

        for (int i = half_line_len; i < line_len; i++)
        {
            if (seen[line.at(i) - 'A'])
            {
                dups.push_back(line.at(i));
                break;
            }
        }
    }

    int total = 0;
    for (char c : dups)
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