#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <vector>

int count_seen(std::vector<std::vector<bool>> seen) {
    int i = 0;
    for(auto vec : seen) {
        for(bool val : vec) {
            if(val) i++;
        }
    }
    return i;
}

int main()
{
    std::ifstream input_stream{"input.txt"};
    std::string line{};
    std::vector<std::vector<int>> grid{};

    while (std::getline(input_stream, line))
    {
        std::vector<int> row{};
        for(char c : line) {
            int i = c - 48;
            row.push_back(i);
        }
        grid.push_back(row);
    }

    std::vector<std::vector<bool>> seen(grid.size(), std::vector<bool>(grid[0].size(), false));

    for(int i = 0; i < grid.size(); i++) {
        int max = -1;
        for(int j = 0; j < grid[0].size(); j++) {
            int curr = grid[i][j];
            if(curr > max) {
                seen[i][j] = true;
                max = curr;
            }
        }
    }

    for(int i = 0; i < grid.size(); i++) {
        int max = -1;
        for(int j = grid[0].size() - 1; j >= 0; j--) {
            int curr = grid[i][j];
            if(curr > max) {
                seen[i][j] = true;
                max = curr;
            }
        }
    }

    for(int j = 0; j < grid[0].size(); j++) {
        int max = -1;
        for(int i = 0; i < grid.size(); i++) {
            int curr = grid[i][j];
            if(curr > max) {
                seen[i][j] = true;
                max = curr;
            }
        }
    }

    for(int j = 0; j < grid[0].size(); j++) {
        int max = -1;
        for(int i = grid.size() - 1; i >= 0; i--) {
            int curr = grid[i][j];
            if(curr > max) {
                seen[i][j] = true;
                max = curr;
            }
        }
    }

    int seen_count = count_seen(seen);
    std::cout << seen_count << std::endl;
}