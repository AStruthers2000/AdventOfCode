#include "Year2023_Day3.h"

#include <numeric>


string Year2023_Day3::Problem1()
{
    engine_schematic = ParseEngine();
    int prev_number = -1;
    int prev_col = -1;
    int prev_row = -1;
    vector<int> part_numbers;
    for(size_t row = 0; row < engine_schematic.size(); row++)
    {
        for(size_t col = 0; col < engine_schematic[0].size(); col++)
        {
            if(LocalSearch(static_cast<int>(col), static_cast<int>(row)))
            {
                //found a symbol in the local space around engine_schematic[row][col]
                const int number = GetNumberAroundSymbol(static_cast<int>(col), static_cast<int>(row));
                if(number != prev_number || prev_row != static_cast<int>(row) || prev_col + 4 <= static_cast<int>(col))
                {
                    prev_row = static_cast<int>(row);
                    prev_col = static_cast<int>(col);
                    part_numbers.push_back(number);
                    //cout << "Symbol around engine_schematic[" <<col << "][" << row << "] = " << engine_schematic[row][col] << endl;
                    //cout << "Number with adjacent symbol: " << number << endl;
                }
                prev_number = number;
            }
        }
    }
    const int sum = accumulate(part_numbers.begin(), part_numbers.end(), 0);
    return to_string(sum);
}

string Year2023_Day3::Problem2()
{
    return "";
}

vector<vector<char>> Year2023_Day3::ParseEngine()
{
    vector<vector<char>> schematic;
    for(size_t l = 0; l < lines.size(); l++)
    {
        string line = lines[l];
        schematic.emplace_back();
        for (char c : line)
        {
            if(c == '.') c = ' ';
            schematic[l].push_back(c);
        }
    }
    row_max = static_cast<int>(schematic.size()) - 1;
    col_max = static_cast<int>(schematic[0].size()) - 1;
    return schematic;
}

bool Year2023_Day3::LocalSearch(const int col, const int row)
{
    vector<char> adjacent;
    const char c = engine_schematic[row][col];
    if(!isdigit(c)) return false;
    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            if(i == 0 && j == 0) continue;
            const int col_pos = col - j;
            const int row_pos = row - i;
            if(IsValidPosition(col_pos, row_pos))
            {
                adjacent.push_back(engine_schematic[row_pos][col_pos]);
            }
        }
    }

    bool has_adjacent_symbol = false;
    for(const auto& symbol : adjacent)
    {
        if(symbol == ' ') continue;
        if(!isdigit(symbol)) has_adjacent_symbol = true;
    }
    return has_adjacent_symbol;
}

int Year2023_Day3::GetNumberAroundSymbol(const int col, const int row) const
{
    vector<int> digits;
    int temp_col = col;
    char c = engine_schematic[row][temp_col];
    while(isdigit(c))
    {
        temp_col--;
        if(temp_col < 0)
        {
            break;
        }
        c = engine_schematic[row][temp_col];
    }

    c = engine_schematic[row][++temp_col];
    while(isdigit(c))
    {
        digits.push_back(c - '0');
        temp_col++;
        if(temp_col > col_max)
        {
            break;
        }
        c = engine_schematic[row][temp_col];
    }
    
    int number = 0;
    for(size_t i = 0; i < digits.size(); i++)
    {
        const int power = static_cast<int>(digits.size() - i);
        number += static_cast<int>(digits[i] * pow(10, power - 1));
    }
    return number;
}
