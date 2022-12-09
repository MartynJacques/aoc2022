#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::ifstream input_stream{"input.txt"};
    std::string line;
    int count = 0;
    int max_count = 0;
    while (std::getline(input_stream, line))
    {
        if(line.empty()) {
            if(count > max_count) {
                max_count = count;
            }
            count = 0;
        } else {
            count = count + std::stoi(line);
        }
    }
    std::cout << max_count << std::endl;
}