#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <vector>

int calculate_scenic_score(int i, int j, std::vector<std::vector<int>> grid) {
    int curr = grid[i][j];

    int up = 0;
    if(i - 1 >= 0) {
        for(int a = i - 1; a >= 0; a--) {
            up++;
            if(grid[a][j] >= curr) {
                break;
            }
        }
    }

    int down = 0;
    if(i + 1 < grid.size()) {
        for(int a = i + 1; a < grid.size(); a++) {
            down++;
            if(grid[a][j] >= curr) {
                break;
            }
        }
    }

    int left = 0;
    if(j - 1 >= 0) {
        for(int a = j - 1; a >= 0; a--) {
            left++;
            if(grid[i][a] >= curr) {
                break;
            }
        }
    }

    int right = 0;
    if(j + 1 < grid[0].size()) {
        for(int a = j + 1; a < grid[0].size(); a++) {
            right++;
            if(grid[i][a] >= curr) {
                break;
            }
        }
    }

    return up * down * left * right;
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

    // int scenic_score = calculate_scenic_score(3, 2, grid);
    // std::cout << scenic_score << std::endl;

    int max = 0;
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            int scenic_score = calculate_scenic_score(i, j, grid);
            if(scenic_score > max) {
                max = scenic_score;
                // std::cout << "val: " << grid[i][j] << " at " << i << ", " << j << std::endl;
            }
        }
    }

    std::cout << max << std::endl;
}