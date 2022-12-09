#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <vector>
#include <sstream>
#include <unordered_set>

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

void update_t(std::pair<int, int> &h, std::pair<int, int> &t)
{
    int iDiff = h.first - t.first;
    int jDiff = h.second - t.second;

    if (jDiff == 2 && iDiff == 0)
    {
        t.second++;
    }
    else if (jDiff == -2 && iDiff == 0)
    {
        t.second--;
    }
    else if (jDiff == 0 && iDiff == 2)
    {
        t.first++;
    }
    else if (jDiff == 0 && iDiff == -2)
    {
        t.first--;
    }
    else if ((iDiff == 2 && jDiff == 1) || (iDiff == 1 && jDiff == 2) || (iDiff == 2 && jDiff == 2))
    {
        t.first++;
        t.second++;
    }
    else if ((iDiff == 1 && jDiff == -2) || (iDiff == 2 && jDiff == -1) || (iDiff == 2 && jDiff == -2))
    {
        t.first++;
        t.second--;
    }
    else if ((iDiff == -1 && jDiff == 2) || (iDiff == -2 && jDiff == 1) || (iDiff == -2 && jDiff == 2))
    {
        t.first--;
        t.second++;
    }
    else if ((iDiff == -2 && jDiff == -1) || (iDiff == -1 && jDiff == -2) || (iDiff == -2 && jDiff == -2))
    {
        t.first--;
        t.second--;
    }
}

struct pair_hash
{
    inline std::size_t operator()(const std::pair<int, int> &v) const
    {
        return v.first * 31 + v.second;
    }
};

int main()
{
    std::ifstream input_stream{"input.txt"};
    std::string line{};

    std::pair<int, int> h{0, 0};
    std::vector<std::pair<int, int>> tails{9, {0, 0}};

    std::unordered_set<std::pair<int, int>, pair_hash> tset{};
    tset.insert(tails[tails.size() - 1]);
    while (std::getline(input_stream, line))
    {
        char direction = line[0];
        auto line_split = split(line, ' ');
        int value = std::stoi(line_split[1]);

        for (int i = 0; i < value; i++)
        {
            if (direction == 'R')
            {
                h.second++;
            }
            else if (direction == 'U')
            {
                h.first--;
            }
            else if (direction == 'L')
            {
                h.second--;
            }
            else if (direction == 'D')
            {
                h.first++;
            }

            update_t(h, tails[0]);
            for (int i = 1; i < 9; i++)
            {
                update_t(tails[i - 1], tails[i]);
            }
            // std::cout << tails[tails.size() - 1].first << ", " << tails[tails.size() - 1].second << std::endl;
            // std::cout << tails[2].first << ", " << tails[2].second << std::endl;
            tset.insert(tails[tails.size() - 1]);
        }
    }
    std::cout << tset.size() << std::endl;
}