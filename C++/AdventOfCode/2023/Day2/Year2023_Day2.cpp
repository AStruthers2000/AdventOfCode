#include "Year2023_Day2.h"

string Year2023_Day2::Problem1()
{
    int sum_possible_games = 0;
    for(const auto& line : lines)
    {
        Game g = BuildGame(line);
        bool possible_game = true;

        for(const auto& s : g.game)
        {
            for(const auto& m : s.revealed_cubes)
            {
                if(m.first < m.second)
                {
                    possible_game = false;
                }
            }
        }
        if(possible_game)
        {
            sum_possible_games += g.game_id;
        }
    }
    return to_string(sum_possible_games);
}

string Year2023_Day2::Problem2()
{
    int sum_powers = 0;
    for(const auto& line : lines)
    {
        Game g = BuildGame(line);
        map<Cube, int> max_set;
        max_set[Red] = 0;
        max_set[Green] = 0;
        max_set[Blue] = 0;
        
        for(const auto& s : g.game)
        {
            for(const auto& m : s.revealed_cubes)
            {
                if(m.second > max_set[m.first])
                {
                    max_set[m.first] = m.second;
                }
            }
        }
        sum_powers += max_set[Red] * max_set[Green] * max_set[Blue];
    }
    return to_string(sum_powers);
}

Year2023_Day2::Game Year2023_Day2::BuildGame(const string& line)
{
    Game game;
    const int game_id = stoi(SplitLineByToken(SplitLineByToken(line, ':')[0], ' ')[1]);
    game.game_id = game_id;

    const string game_sets = SplitLineByToken(line, ':')[1];
    const vector<string> games = SplitLineByToken(game_sets, ';');
    for(const auto& pull : games)
    {
        GameSet set;
        vector<string> cubes = SplitLineByToken(pull, ',');
        for(const auto& cube : cubes)
        {
            const int cube_num = stoi(SplitLineByToken(cube, ' ')[1]);
            string cube_color = SplitLineByToken(cube, ' ')[2];
            
            if(cube_color == "red") set.revealed_cubes.emplace(Red, cube_num);
            if(cube_color == "green") set.revealed_cubes.emplace(Green, cube_num);
            if(cube_color == "blue") set.revealed_cubes.emplace(Blue, cube_num);
        }
        game.game.push_back(set);
    }
    return game;
}
