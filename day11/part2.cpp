#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <vector>
#include <sstream>
#include <unordered_set>
#include <memory>
#include <algorithm>

class Monkey
{
public:
    std::vector<std::int64_t> items;
    std::int64_t inspections = 0;
    std::int64_t (*operation)(std::int64_t);
    std::int64_t (*test)(std::int64_t);
};

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
    std::vector<std::unique_ptr<Monkey>> monkeys;

    auto monkey_zero = std::make_unique<Monkey>();
    monkey_zero->items = {56, 52, 58, 96, 70, 75, 72};
    monkey_zero->operation = [](std::int64_t i) -> std::int64_t
    { return i * 17; };
    monkey_zero->test = [](std::int64_t i) -> std::int64_t
    { return i % 11 == 0 ? 2 : 3; };
    monkeys.push_back(std::move(monkey_zero));

    auto monkey_one = std::make_unique<Monkey>();
    monkey_one->items = {75, 58, 86, 80, 55, 81};
    monkey_one->operation = [](std::int64_t i) -> std::int64_t
    { return i + 7; };
    monkey_one->test = [](std::int64_t i) -> std::int64_t
    { return i % 3 == 0 ? 6 : 5; };
    monkeys.push_back(std::move(monkey_one));

    auto monkey_two = std::make_unique<Monkey>();
    monkey_two->items = {73, 68, 73, 90};
    monkey_two->operation = [](std::int64_t i) -> std::int64_t
    { return i * i; };
    monkey_two->test = [](std::int64_t i) -> std::int64_t
    { return i % 5 == 0 ? 1 : 7; };
    monkeys.push_back(std::move(monkey_two));

    auto monkey_three = std::make_unique<Monkey>();
    monkey_three->items = {72, 89, 55, 51, 59};
    monkey_three->operation = [](std::int64_t i) -> std::int64_t
    { return i + 1; };
    monkey_three->test = [](std::int64_t i) -> std::int64_t
    { return i % 7 == 0 ? 2 : 7; };
    monkeys.push_back(std::move(monkey_three));

    auto monkey_four = std::make_unique<Monkey>();
    monkey_four->items = {76, 76, 91};
    monkey_four->operation = [](std::int64_t i) -> std::int64_t
    { return i * 3; };
    monkey_four->test = [](std::int64_t i) -> std::int64_t
    { return i % 19 == 0 ? 0 : 3; };
    monkeys.push_back(std::move(monkey_four));

    auto monkey_five = std::make_unique<Monkey>();
    monkey_five->items = {88};
    monkey_five->operation = [](std::int64_t i) -> std::int64_t
    { return i + 4; };
    monkey_five->test = [](std::int64_t i) -> std::int64_t
    { return i % 2 == 0 ? 6 : 4; };
    monkeys.push_back(std::move(monkey_five));

    auto monkey_six = std::make_unique<Monkey>();
    monkey_six->items = {64, 63, 56, 50, 77, 55, 55, 86};
    monkey_six->operation = [](std::int64_t i) -> std::int64_t
    { return i + 8; };
    monkey_six->test = [](std::int64_t i) -> std::int64_t
    { return i % 13 == 0 ? 4 : 0; };
    monkeys.push_back(std::move(monkey_six));

    auto monkey_seven = std::make_unique<Monkey>();
    monkey_seven->items = {79, 58};
    monkey_seven->operation = [](std::int64_t i) -> std::int64_t
    { return i + 6; };
    monkey_seven->test = [](std::int64_t i) -> std::int64_t
    { return i % 17 == 0 ? 1 : 5; };
    monkeys.push_back(std::move(monkey_seven));

    for (std::int64_t i = 0; i < 10000; i++)
    {
        for (auto &monkey : monkeys)
        {
            while (monkey->items.size() != 0)
            {
                monkey->inspections++;
                std::int64_t curr_item = monkey->items[0];
                monkey->items.erase(monkey->items.begin());
                curr_item = monkey->operation(curr_item);
                curr_item %= (11 * 3 * 5 * 7 * 19 * 2 * 13 * 17);
                std::int64_t throw_to = monkey->test(curr_item);
                monkeys[throw_to]->items.push_back(curr_item);
            }
        }
    }

    std::vector<std::int64_t> totals{};
    for (auto &monkey : monkeys)
    {
        totals.push_back(monkey->inspections);
    }
    std::sort(totals.begin(), totals.end());
    std::cout << totals[6] << ", " << totals[7];
    std::cout << " : " << totals[6] * totals[7] << std::endl;
}