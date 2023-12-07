#include "Year2023_Day7.h"

bool part_two = false;

string Year2023_Day7::Problem1()
{
    ReadHands();

    int total_winnings = 0;
    int rank = 0;
    for(const auto& hand : hands)
    {
        total_winnings += hand.second * ++rank;
    }
    return to_string(total_winnings);
}

string Year2023_Day7::Problem2()
{
    part_two = true;
    return Problem1();
}

void Year2023_Day7::ReadHands()
{
    hands.clear();
    for(const auto& line : lines)
    {
        Hand h;
        string hand = SplitLineByToken(line, ' ')[0];
        for(const auto& card : hand)
        {
            h.cards.push_back(card);
        }
        FigureOutType(&h);
        hands.emplace(h, stoi(SplitLineByToken(line, ' ')[1]));
    }
}

void Year2023_Day7::FigureOutType(Hand* hand)
{
    map<char, int> occurrences;
    for(const auto& c : hand->cards)
    {
        auto n = count(hand->cards.begin(), hand->cards.end(), c);
        occurrences.emplace(c, n);
    }
    
    if(part_two)
    {
        const char most = GetMostCardFromMap(occurrences).first;
        string modified_hand = {hand->cards.begin(), hand->cards.end()};
        replace(modified_hand.begin(), modified_hand.end(), 'J', most);
        occurrences.clear();
        for(const auto& c : modified_hand)
        {
            auto n = count(modified_hand.begin(), modified_hand.end(), c);
            occurrences.emplace(c, n);
        }
    }
    
    const int card_count = static_cast<int>(occurrences.size());
    switch (card_count)
    {
    case 1:
        hand->type = FiveOfAKind;
        break;
    case 2:
        if(DoesValueExistInMap(occurrences, 4)) hand->type = FourOfAKind;
        else hand->type = FullHouse;
        break;
    case 3:
        if(DoesValueExistInMap(occurrences, 3)) hand->type = ThreeOfAKind;
        else hand->type = TwoPair;
        break;
    case 4:
        hand->type = OnePair;
        break;
    default: hand->type = HighCard;
    }
}

int Year2023_Day7::GetCardRank(const char& card)
{
    if(isdigit(card)) return card - '0';
    switch (card)
    {
    case 'A': return 14;
    case 'K': return 13;
    case 'Q': return 12;
    case 'J':
        if(!part_two) return 11;
        return 1;
    case 'T': return 10;
    default: return 0;
    }
}
