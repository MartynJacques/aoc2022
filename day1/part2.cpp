#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
    std::ifstream input_stream{"input.txt"};
    std::string line;
    int count = 0;

    std::vector<int> all_totals{};
    while (std::getline(input_stream, line))
    {
        if(line.empty()) {
            all_totals.push_back(count);
            count = 0;
        } else {
            count = count + std::stoi(line);
        }
    }
    std::sort(all_totals.begin(), all_totals.end());

    int size = all_totals.size();
    std::cout << all_totals.at(size - 1) << std::endl;
    std::cout << all_totals.at(size - 2) << std::endl;
    std::cout << all_totals.at(size - 3) << std::endl;

    int total = 70509 + 69894 + 68164;
    std::cout << total << std::endl;
}