#pragma once
#include "../../Problem.h"

#define LOOP_BOUND '#'

class Year2023_Day10 : public Problem
{
public:
    Year2023_Day10() : Problem("Year 2023 day 10: Pipe Maze")
    {
        filepath = R"(./2023/Day10/)";
        
    }

    string Problem1() override;
    string Problem2() override;

private:
    vector<vector<char>> maze;
    void ReadMaze();

    struct MazeCoord
    {
        int row = -1;
        int col = -1;
        char maze_tile;

        MazeCoord(const int r, const int c, const char t)
        {
            row = r;
            col = c;
            maze_tile = t;
        }

        MazeCoord() = default;

        bool operator==(const MazeCoord& other) const
        {
            return row == other.row && col == other.col;
        }

        bool operator!=(const MazeCoord& other) const
        {
            return row != other.row || col != other.col;
        }
    };

    MazeCoord start;
    MazeCoord default_coord = {-1, -1, ' '};
    vector<MazeCoord> loop;

    void TraverseMaze(MazeCoord prev, MazeCoord cur);
    void TraverseMaze();
    vector<MazeCoord> GetValidSurroundingPipes(MazeCoord cur);
    void ConvertLoopToBound();
    int CheckGroundPointsInMaze();

    void PrintMaze();
};
