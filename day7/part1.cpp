#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <array>
#include <vector>
#include <memory>

class Node
{
public:
    int size;
    std::vector<std::shared_ptr<Node>> children;
    std::shared_ptr<Node> parent;
    std::string name;

    Node()
    {
        size = 0;
        children = std::vector<std::shared_ptr<Node>>();
    }

    Node(int _size)
    {
        size = _size;
        children = std::vector<std::shared_ptr<Node>>();
    }

    Node(int _size, std::vector<std::shared_ptr<Node>> _children)
    {
        size = _size;
        children = _children;
    }
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

std::string parse_dir_name(std::string &line)
{
    std::vector<std::string> split_string = split(line, ' ');
    return split_string[2];
}

std::shared_ptr<Node> find_node(std::shared_ptr<Node> node, std::string &dir_name)
{
    for (std::shared_ptr<Node> curr : node->children)
    {
        if (curr->name == dir_name)
            return curr;
    }
}

int main()
{
    std::shared_ptr<Node> graph{};
    graph->parent = graph;

    std::ifstream input_stream{"input.txt"};
    std::string line{};
    std::shared_ptr<Node> current = graph;
    while (std::getline(input_stream, line))
    {
        std::vector<std::string> line_split = split(line, ' ');
        if (line_split[0] == "dir")
        {
            std::cout << "dir " << line << std::endl;
        }
        else if (line_split[1] == "cd")
        {
            std::cout << "cd " << line << std::endl;
        }
        else if (line_split[1] != "ls")
        {
            // file
            std::cout << "ls " << line << std::endl;
        }
    }
}