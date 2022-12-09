#include <iostream>
#include <string>
#include <fstream>
#include <map>

int main() {
    std::map<std::string, int> choice_map{
        {"AX", 4},
        {"AY", 8},
        {"AZ", 3},
        {"BX", 1},
        {"BY", 5},
        {"BZ", 9},
        {"CX", 7},
        {"CY", 2},
        {"CZ", 6},
    };

    std::ifstream input_stream{"input.txt"};
    std::string line;
    int total = 0;
    while (std::getline(input_stream, line))
    {
        char opponent_choice = line.at(0);
        char my_choice = line.at(2);
        std::string combination = std::string() + opponent_choice + my_choice;
        total = total + choice_map[combination];
    }
    std::cout << total << std::endl;
}