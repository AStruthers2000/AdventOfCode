#include "Year2023_Day4.h"

string Year2023_Day4::Problem1()
{
    int sum_card_points = 0;
    LoadCards();
    for(const auto& card : cards)
    {
        sum_card_points += card.score;
    }
    return to_string(sum_card_points);
}

string Year2023_Day4::Problem2()
{
    int number_of_card_instances = 0;
    InstanceCount();
    for(const auto& card : cards)
    {
        number_of_card_instances += card.instance_count;
    }
    return to_string(number_of_card_instances);
}

void Year2023_Day4::LoadCards()
{
    for(const auto& line : lines)
    {
        Card this_card;

        //read card ID
        vector<string> card_id_str = SplitLineByToken(SplitLineByToken(line, ':')[0], ' ');
        const int card_id = stoi(card_id_str[card_id_str.size()-1]);
        this_card.card_id = card_id;

        this_card.instance_count = 1;

        //read all numbers, splitting them into [0] = winning numbers, [1] = my numbers
        vector<string> split_card_nums = SplitLineByToken(SplitLineByToken(line, ':')[1], '|');

        //add all winning numbers to the card
        for(const auto& winning_num : SplitLineByToken(split_card_nums[0], ' '))
        {
            if(winning_num.empty()) continue;
            int num = stoi(winning_num);
            this_card.winning_numbers.push_back(num);
        }

        //add all my numbers to the card, and check if my number is in the winning numbers
        for(const auto& my_num : SplitLineByToken(split_card_nums[1], ' '))
        {
            if(my_num.empty()) continue;
            int num = stoi(my_num);
            this_card.my_numbers.push_back(num);
            
            const auto v_begin = this_card.winning_numbers.begin();
            const auto v_end = this_card.winning_numbers.end();
            if(find(v_begin, v_end, num) != v_end)
            {
                if(this_card.score == 0) this_card.score = 1;
                else this_card.score *= 2;

                this_card.win_count++;
            }
        }

        cards.push_back(this_card);
    }
}

void Year2023_Day4::InstanceCount()
{
    for(size_t i = 0; i < cards.size(); i++)
    {
        const Card c = cards[i];
        
        for(int i_offset = 1; i_offset <= c.win_count; i_offset++)
        {
            cards[i + i_offset].instance_count += c.instance_count;
        }
    }
}
