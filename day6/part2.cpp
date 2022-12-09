#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <vector>
#include <deque>
#include <limits>

bool find_dups(std::deque<char> &q)
{
    int count[127] = {0};
    for (char c : q)
    {
        if (count[c] == 1)
            return true;
        count[c]++;
    }
    return false;
}

int main()
{
    std::ifstream input_stream{"input.txt"};
    std::string line{};
    std::getline(input_stream, line);
    input_stream.close();

    std::cout << line << std::endl;

    std::deque<char> queue{};
    for (int i = 0; i < std::numeric_limits<int>::max(); i++)
    {
        if (queue.size() == 14)
        {
            if (!find_dups(queue))
            {
                std::cout << i << std::endl;
                break;
            }
            queue.pop_front();
            queue.push_back(line[i]);
        }
        else
        {
            queue.push_back(line[i]);
        }
    }
}