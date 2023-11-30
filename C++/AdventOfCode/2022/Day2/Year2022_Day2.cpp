#include "Year2022_Day2.h"

string Year2022_Day2::Problem1()
{
    int round_sum = 0;
    auto rounds = GetRounds();
    for(auto& round : rounds)
    {
        round.round_result = GetState(round.my_move, round.opponent_move);
        const int result = round.round_result;
        const int move = round.my_move; 
        round_sum += result + move;
    }
    return to_string(round_sum);
}

string Year2022_Day2::Problem2()
{
    int round_sum = 0;
    auto rounds = GetRounds();
    for(auto& round : rounds)
    {
        round.round_result = ConvertMoveToState(round.my_move);
        round.my_move = GetMoveThatResultsInState(round.opponent_move, round.round_result);
        const int result = round.round_result;
        const int move = round.my_move;
        round_sum += result + move;
    }
    return to_string(round_sum);
}

vector<Year2022_Day2::RPS_Round> Year2022_Day2::GetRounds() const
{
    vector<RPS_Round> rounds;
    for(const auto& line : lines)
    {
        RPS_Round round;
        round.round_result = Undefined;
        
        auto split = SplitLineByToken(line, ' ');
        switch (split[0][0])
        {
        case 'A':
            round.opponent_move = Rock;
            break;
        case 'B':
            round.opponent_move = Paper;
            break;
        case 'C':
            round.opponent_move = Scissors;
            break;
        default: break;
        }

        switch (split[1][0])
        {
        case 'X':
            round.my_move = Rock;
            break;
        case 'Y':
            round.my_move = Paper;
            break;
        case 'Z':
            round.my_move = Scissors;
            break;
        default: break;
        }

        rounds.push_back(round);
    }
    return rounds;
}

Year2022_Day2::RPS_State Year2022_Day2::GetState(const RPS_Move my_move, const RPS_Move opponent_move) const
{
    RPS_State state;
    if(my_move == opponent_move) state = Tie;
    else if(my_move == opponent_move + 1 || my_move == opponent_move - 2) state = Win;
    else state = Lose;
    return state;
}

Year2022_Day2::RPS_Move Year2022_Day2::GetMoveThatResultsInState(const RPS_Move opponent_move, const RPS_State state) const
{
    RPS_Move my_move = Rock;
    const vector<RPS_Move> possible_moves = {Rock, Paper, Scissors};
    for(const auto& possible_move : possible_moves)
    {
        if(GetState(possible_move, opponent_move) == state) my_move = possible_move;
    }
    return my_move;
}

Year2022_Day2::RPS_State Year2022_Day2::ConvertMoveToState(RPS_Move move) const
{
    RPS_State state = Undefined;
    switch(move)
    {
    case Rock:
        state = Lose;
        break;
    case Paper:
        state = Tie;
        break;
    case Scissors:
        state = Win;
        break;
    }
    return state;
}

void Year2022_Day2::UnitTestState() const
{
    const vector<RPS_Move> all_moves = {Rock, Paper, Scissors};
    for(const auto& my_move : all_moves)
    {
        for(const auto& op_move : all_moves)
        {
            string my = my_move == Rock ? "Rock" : my_move == Paper ? "Paper" : my_move == Scissors ? "Scissors" : "Uhh";
            string op = op_move == Rock ? "Rock" : op_move == Paper ? "Paper" : op_move == Scissors ? "Scissors" : "Uhh";
            const RPS_State result = GetState(my_move, op_move);
            string r = result == Lose ? "Lose" : result == Tie ? "Tie" : "Win";

            cout << "I played " << my << ", opponent played " << op << ". I " << r << endl;
        }
    }
}
