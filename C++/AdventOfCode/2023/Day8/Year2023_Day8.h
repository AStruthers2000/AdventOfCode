#pragma once
#include "../../Problem.h"

#define FIRST_NODE "AAA"
#define LAST_NODE "ZZZ"

class Year2023_Day8 : public Problem
{
public:
    Year2023_Day8() : Problem("Year 2023 Day 8: Haunted Wasteland")
    {
        filepath = R"(./2023/Day8/)";
    }

    string Problem1() override;
    string Problem2() override;

private:
    struct Node
    {
        Node* left;
        Node* right;
        string left_name;
        string right_name;
        string node_name;

        Node(const vector<string>& node)
        {
            //left = nullptr;
            //right = nullptr;
            node_name = node[0];
            left_name = node[1];
            right_name = node[2];
        }
        
        bool operator==(const Node& rhs) const
        {
             return node_name == rhs.node_name;   
        }
    };


    void ReadInstructions();
    void ReadNodes();
    
    vector<char> instructions;
    vector<Node*> all_nodes;
    vector<Node*> starting_nodes;
    vector<Node*> ending_nodes;
    Node* GetNodeFromName(const string& name)
    {
        for(const auto& node : all_nodes)
        {
            if(node->node_name == name)
            {
                return node;
            }
        }
        return nullptr;
    }
    
    vector<string> CleanNode(string node_string) const;
    Node* StepInstruction(const char& instruction, const Node* current);
    vector<Node*> StepInstruction(const char& instruction, const vector<Node*>& current);
    int GoFromStartToEnd(Node* start);
    bool AtTheEnd(const Node* node) const;
};
