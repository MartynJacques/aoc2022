#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <array>
#include <vector>
#include <deque>

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
    std::vector<std::deque<char>> queues{};

    int num_vecs = 0;
    while (std::getline(input_stream, line))
    {
        if (line[1] == '1')
        {
            num_vecs = (int)line[line.size() - 1] - 48;
            break;
        }
    }

    for (int i = 0; i < num_vecs; i++)
    {
        queues.push_back(std::deque<char>{});
    }

    std::ifstream other_input_stream{"input.txt"};
    bool doing_grid = true;
    while (std::getline(other_input_stream, line))
    {
        if (line[1] == '1')
        {
            doing_grid = false;
            continue;
        }

        if (line == "")
            continue;

        if (doing_grid)
        {
            int i = 0;
            int queue_num = 0;
            while (i < line.size())
            {
                if (line[i] == '[')
                {
                    queues[queue_num].push_back(line[i + 1]);
                }
                i += 4;
                queue_num++;
            }
        }
        else
        {
            auto line_split = split(line, ' ');
            int moves = std::stoi(line_split[1]);
            int from = std::stoi(line_split[3]) - 1;
            int to = std::stoi(line_split[5]) - 1;

            std::deque<char> reordered{};
            for (int i = 0; i < moves; i++)
            {
                if (!queues[from].empty())
                {
                    char c = queues[from].front();
                    queues[from].pop_front();
                    reordered.push_front(c);
                }
            }

            while (!reordered.empty())
            {
                char c = reordered.front();
                reordered.pop_front();
                queues[to].push_front(c);
            }
        }
    }

    for (auto q : queues)
    {
        for (char c : q)
        {
            std::cout << c;
            break;
        }
    }
}