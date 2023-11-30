#include "Year2022_Day5.h"

string Year2022_Day5::Problem1()
{
    ParseInput();
    for(const auto& instruction : instructions)
    {
        for(int moves = 0; moves < instruction.number_to_move; moves++)
        {
            string box = boxes.at(instruction.from).front();
            boxes.at(instruction.from).pop_front();
            boxes.at(instruction.to).push_front(box);
        }
    }
    string top_boxes;
    for(const auto& column : boxes)
    {
        top_boxes += column.second.front()[1];
    }
    
    return top_boxes;
}

string Year2022_Day5::Problem2()
{
    ParseInput();
    return "";
}

void Year2022_Day5::ParseInput()
{
    bool reading_boxes = true;
    for(const auto& line : lines)
    {
        if(line.empty())
        {
            reading_boxes = false;
            continue;
        }
        if(reading_boxes)
        {
            int box_index = 1;
            vector<string> box_row = SplitStringIntoBoxes(line);
            for(const auto& box : box_row)
            {
                if(box[0]!=' ') boxes[box_index].push_back(box);
                box_index++;
            }
        }
        else
        {
            instructions.push_back(ParseInstruction(line));
        }
    }
}

vector<string> Year2022_Day5::SplitStringIntoBoxes(string line)
{
    vector<string> box_row;
    for(size_t i = 0; i < line.size(); i+=4)
    {
        box_row.push_back({line[i], line[i+1], line[i+2]});
    }
    return box_row;
}

Year2022_Day5::MoveInstruction Year2022_Day5::ParseInstruction(string line)
{
    MoveInstruction i;
    const vector<string> split_line = SplitLineByToken(line, ' ');
    i.number_to_move = stoi(split_line[1]);
    i.from = stoi(split_line[3]);
    i.to = stoi(split_line[5]);
    return i;
}
