#pragma once
#include <map>

#include "../../Problem.h"

class Year2023_Day2 : public Problem
{
public:
    Year2023_Day2() : Problem("Year 2022 Day 2: Cube Conundrum")
    {
        filepath = R"(./2023/Day2/)";
    }

    string Problem1() override;
    string Problem2() override;

private:
    enum Cube
    {
        Red = 12,
        Green = 13,
        Blue = 14
    };

    struct GameSet
    {
        map<Cube, int> revealed_cubes;
    };

    struct Game
    {
        int game_id = 0;
        vector<GameSet> game;
    };

    Game BuildGame(const string& line);
};
