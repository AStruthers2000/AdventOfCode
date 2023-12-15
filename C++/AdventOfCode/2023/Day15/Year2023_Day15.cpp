#include "Year2023_Day15.h"

string Year2023_Day15::Problem1()
{
    LoadHashes();

    int sum = 0;
    for(const auto& hash : hashes)
    {
        //cout << " - " << hash.unhashed_string << " becomes " << hash.hashed_value << endl;
        sum += hash.hashed_value;
    }
    return to_string(sum);
}

string Year2023_Day15::Problem2()
{
    LoadHashes();
    ManualArrangementProcedure();

    int focusing_power = 0;
    for(int i = 0; i < BoxCount_Default; i++)
    {
        const int box_num = i + 1;
        int slot_num = 1;
        for(const auto& lens : boxes[i].lenses)
        {
            focusing_power += box_num * slot_num * lens.focal_length;
            slot_num++;
        }
    }
    
    return to_string(focusing_power);
}

void Year2023_Day15::LoadHashes()
{
    if(!hashes.empty()) return;
    
    for(const auto& line : lines)
    {
        vector<string> init_sequence = SplitLineByToken(line, ',');
        for(const auto& seq : init_sequence)
        {
            StringHash h;
            h.unhashed_string = seq;
            h.hashed_value = HashString(h.unhashed_string);

            for(const auto& c : seq)
            {
                if(!isdigit(c) && c != '-' && c != '=')
                {
                    h.label += c;
                }
                else if(isdigit(c))
                {
                    h.focal_length = c - '0';
                }
                else if(c == '-')
                {
                    h.operation = Remove;
                }
                else
                {
                    h.operation = Add;
                }
            }
            
            hashes.push_back(h);
        }
    }
}

int Year2023_Day15::HashString(const string& s)
{
    int hash_value = 0;
    for(const auto& c : s)
    {
        const int ascii = static_cast<unsigned char>(c);
        hash_value += ascii;
        hash_value *= HashPrime_Default;
        hash_value %= BoxCount_Default;
    }

    return hash_value;
}

void Year2023_Day15::ManualArrangementProcedure()
{
    for(const auto& hash : hashes)
    {
        const int box_num = HashString(hash.label);
        const bool is_lens_present = IsLensPresent(hash.label, box_num);
        const int lens_location = WhereIsLensPresent(hash.label, box_num);
        if(hash.operation == Remove)
        {
            if(is_lens_present)
            {
                boxes[box_num].lenses.erase(boxes[box_num].lenses.begin() + lens_location);
            }
        }
        else
        {
            if(is_lens_present)
            {
                boxes[box_num].lenses.at(lens_location) = hash;
            }
            else
            {
                boxes[box_num].lenses.push_back(hash);
            }
        }
    }
}

bool Year2023_Day15::IsLensPresent(const string& label, const int box_num) const
{
    const vector<StringHash> lenses = boxes[box_num].lenses;
    return any_of(lenses.begin(), lenses.end(),
        [label](const auto& lens)
        {
            return label == lens.label;
        }
    );
}

int Year2023_Day15::WhereIsLensPresent(const string& label, int box_num) const
{
    const vector<StringHash> lenses = boxes[box_num].lenses;
    for(size_t i = 0; i < lenses.size(); i++)
    {
        if(lenses[i].label == label)
        {
            return static_cast<int>(i);
        }
    }
    return -1;
}
