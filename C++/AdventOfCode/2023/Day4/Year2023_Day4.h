#pragma once
#include "../../Problem.h"

class Year2023_Day4 : public Problem
{
public:
    Year2023_Day4() : Problem("Year 2023 Day 4: Scratchcards")
    {
        filepath = R"(./2023/Day4/)";
    }

    string Problem1() override;
    string Problem2() override;

private:
    struct Card
    {
        int card_id = 0;
        vector<int> winning_numbers;
        vector<int> my_numbers;
        int score = 0;
        int win_count = 0;
        int instance_count = 0;
    };
    vector<Card> cards;
    void LoadCards();
    void InstanceCount();
};
