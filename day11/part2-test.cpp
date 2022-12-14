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
    monkey_zero->items = {79, 98};
    monkey_zero->operation = [](std::int64_t i) -> std::int64_t
    { return i * 19; };
    monkey_zero->test = [](std::int64_t i) -> std::int64_t
    { return i % 23 == 0 ? 2 : 3; };
    monkeys.push_back(std::move(monkey_zero));

    auto monkey_one = std::make_unique<Monkey>();
    monkey_one->items = {54, 65, 75, 74};
    monkey_one->operation = [](std::int64_t i) -> std::int64_t
    { return i + 6; };
    monkey_one->test = [](std::int64_t i) -> std::int64_t
    { return i % 19 == 0 ? 2 : 0; };
    monkeys.push_back(std::move(monkey_one));

    auto monkey_two = std::make_unique<Monkey>();
    monkey_two->items = {79, 60, 97};
    monkey_two->operation = [](std::int64_t i) -> std::int64_t
    { return i * i; };
    monkey_two->test = [](std::int64_t i) -> std::int64_t
    { return i % 13 == 0 ? 1 : 3; };
    monkeys.push_back(std::move(monkey_two));

    auto monkey_three = std::make_unique<Monkey>();
    monkey_three->items = {74};
    monkey_three->operation = [](std::int64_t i) -> std::int64_t
    { return i + 3; };
    monkey_three->test = [](std::int64_t i) -> std::int64_t
    { return i % 17 == 0 ? 0 : 1; };
    monkeys.push_back(std::move(monkey_three));

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
                curr_item %= (23 * 19 * 13 * 17);
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
    std::cout << totals[2] << ", " << totals[3];
    std::cout << " : " << totals[2] * totals[3] << std::endl;
}