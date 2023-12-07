#pragma once
#include <map>

#include "../../Problem.h"

class Year2023_Day7 : public Problem
{
public:
    Year2023_Day7() : Problem("Year 2023 Day 7: Camel Cards")
    {
        filepath = R"(./2023/Day7/)";
    }

    string Problem1() override;
    string Problem2() override;

private:
    enum HandType
    {
        HighCard,
        OnePair,
        TwoPair,
        ThreeOfAKind,
        FullHouse,
        FourOfAKind,
        FiveOfAKind,
    };
    struct Hand
    {
        vector<char> cards;
        HandType type;
        int rank = 0;
    };

    struct HandCompare
    {
        bool operator()(const Hand& this_hand, const Hand& other_hand) const
        {
            if(this_hand.type > other_hand.type) return false;
            if(this_hand.type < other_hand.type) return true;

            for(size_t i = 0; i < this_hand.cards.size(); i++)
            {
                const int this_card_rank = GetCardRank(this_hand.cards[i]);
                const int other_card_rank = GetCardRank(other_hand.cards[i]);

                if(this_card_rank > other_card_rank) return false;
                if(this_card_rank < other_card_rank) return true;
            }

            return false;
        }
    };
    
    map<Hand, int, HandCompare> hands;

    void ReadHands();
    void FigureOutType(Hand* hand);
    static int GetCardRank(const char& card);
    
    static pair<char, int> GetMostCardFromMap(const map<char, int>& occurrences)
    {
        pair<char, int> entry = {'0', 0};
        if(occurrences.size() < 5)
        {
            for(auto it = occurrences.begin(); it != occurrences.end(); ++it)
            {
                if(it->second > entry.second && it->first != 'J')
                {
                    entry = {it->first, it->second};
                }
            }
            return entry;
        }
        
        for(auto it = occurrences.begin(); it != occurrences.end(); ++it)
        {
            if(GetCardRank(it->first) > entry.second)
            {
                entry = {it->first, GetCardRank(it->first)};
            }
        }
        return entry;
    }

    static string EnumToString(const HandType h)
    {
        switch (h) {
        case HighCard:
            return "High Card";
        case OnePair:
            return "One Pair";
        case TwoPair:
            return "Two Pair";
        case ThreeOfAKind:
            return "Three of a Kind";
        case FullHouse:
            return "Full House";
        case FourOfAKind:
            return "Four of a Kind";
        case FiveOfAKind:
            return "Five of a Kind";
        }
        return "";
    }

    static bool DoesValueExistInMap(const map<char, int>& occurrences, const int val) 
    {
        for(const auto& o : occurrences)
        {
            if(o.second == val) return true;
        }
        return false;
    }
};
