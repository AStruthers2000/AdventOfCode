#include "Year2023_Day8.h"

bool problem_two = false;

string Year2023_Day8::Problem1()
{
    problem_two = false;
    ReadInstructions();
    ReadNodes();
    
    const int number_steps = GoFromStartToEnd(GetNodeFromName(FIRST_NODE));
    return to_string(number_steps);
}

string Year2023_Day8::Problem2()
{
    problem_two = true;
    if(instructions.empty()) ReadInstructions();
    if(all_nodes.empty()) ReadNodes();

    vector<int> required_steps;
    for(const auto& n : starting_nodes)
    {
        const int num_steps = GoFromStartToEnd(n);
        required_steps.push_back(num_steps);
    }
    const uint64_t least = lcm(required_steps);
    return to_string(least);
}

void Year2023_Day8::ReadInstructions()
{
    const string instruction = lines[0];
    for(const auto& c : instruction)
    {
        instructions.push_back(c);
    }
}

void Year2023_Day8::ReadNodes()
{
    const vector<string> nodes = {lines.begin() + 2, lines.end()};
    for(const string& node_string : nodes)
    {
        vector<string> cleaned = CleanNode(node_string);
        auto node = new Node(cleaned);
        all_nodes.emplace_back(node);

        const char end_char = *(node->node_name.end()-1);
        if(end_char == 'A') starting_nodes.push_back(node);
        if(end_char == 'Z') ending_nodes.push_back(node);
    }

    for(const auto& n : all_nodes)
    {
        n->left = GetNodeFromName(n->left_name);
        n->right = GetNodeFromName(n->right_name);
    }
}

vector<string> Year2023_Day8::CleanNode(string node_string) const
{
    replace(node_string.begin(), node_string.end(), '=', ' ');
    replace(node_string.begin(), node_string.end(), '(', ' ');
    replace(node_string.begin(), node_string.end(), ')', ' ');
    replace(node_string.begin(), node_string.end(), ',', ' ');
    const vector<string> split_node = SplitLineByToken(node_string, ' ');
    vector<string> cleaned_node;
    for(const auto& s : split_node)
    {
        if(s.empty()) continue;
        cleaned_node.push_back(s);
    }
    return cleaned_node;
}

Year2023_Day8::Node* Year2023_Day8::StepInstruction(const char& instruction, const Node* current)
{
    switch (instruction)
    {
    case 'R': return current->right;
    case 'L': return current->left;
    default: return nullptr;
    }
}

vector<Year2023_Day8::Node*> Year2023_Day8::StepInstruction(const char& instruction, const vector<Node*>& current)
{
    vector<Node*> next_step;
    next_step.reserve(current.size());
    for(const auto& n : current)
    {
        next_step.push_back(StepInstruction(instruction, n));
    }
    return next_step;
}

int Year2023_Day8::GoFromStartToEnd(Node* start)
{
    int instruction_num = 0;
    const int instruction_count = static_cast<int>(instructions.size());
    Node* current = start;
    while(!AtTheEnd(current))
    {
        current = StepInstruction(instructions[instruction_num++%instruction_count], current);
    }
    return instruction_num;
}

bool Year2023_Day8::AtTheEnd(const Node* node) const
{
    if(problem_two) return *(node->node_name.end()-1) == 'Z';
    return node->node_name == LAST_NODE;
}
