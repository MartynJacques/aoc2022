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

    std::cout << "before" << std::endl;
    std::cout << "h: " << h.first << "," << h.second << " t: " << t.first << "," << t.second << std::endl;

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
    else if ((iDiff == 2 && jDiff == 1) || (iDiff == 1 && jDiff == 2))
    {
        t.first++;
        t.second++;
    }
    else if ((iDiff == 1 && jDiff == -2) || (iDiff == 2 && jDiff == -1))
    {
        t.first++;
        t.second--;
    }
    else if ((iDiff == -1 && jDiff == 2) || (iDiff == -2 && jDiff == 1))
    {
        t.first--;
        t.second++;
    }
    else if ((iDiff == -2 && jDiff == -1) || (iDiff == -1 && jDiff == -2))
    {
        t.first--;
        t.second--;
    }
    std::cout << "iDiff: " << iDiff << " jDiff: " << jDiff << std::endl;
    std::cout << "after" << std::endl;
    std::cout << "h: " << h.first << "," << h.second << " t: " << t.first << "," << t.second << std::endl;
    std::cout << std::endl;
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
    std::pair<int, int> t{0, 0};

    std::unordered_set<std::pair<int, int>, pair_hash> tset{};
    tset.insert(t);
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
            // std::cout << "h: " << h.first << "," << h.second << std::endl;
            // std::cout << std::endl;
            update_t(h, t);
            tset.insert(t);
        }
    }
    std::cout << tset.size() << std::endl;
}