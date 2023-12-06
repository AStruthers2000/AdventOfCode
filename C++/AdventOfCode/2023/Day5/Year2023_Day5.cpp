#include "Year2023_Day5.h"

string Year2023_Day5::Problem1()
{
    BuildConversionMaps();
    BuildSeeds_Standard();
    ConvertSeeds();
    
    
    const Seed* min_seed = GetSeedWithSmallestLocation();
    return to_string(min_seed->mapped_values.at(HumidityToLocation));
}

string Year2023_Day5::Problem2()
{
    if(conversion_maps.empty()) BuildConversionMaps();
    BuildSeeds_Ranged();
    ConvertSeeds();
    const Seed* min_seed = GetSeedWithSmallestLocation();
    return to_string(min_seed->mapped_values.at(HumidityToLocation));
}

void Year2023_Day5::BuildSeeds_Standard()
{
    seeds.clear();
    vector<string> seed_ints = SplitLineByToken(lines[0], ' ');
    seed_ints = {seed_ints.begin() + 1, seed_ints.end()};
    for(const auto& s : seed_ints)
    {
        const int64_t s_int = strtoll(s.c_str(), nullptr, 10);
        Seed seed = {s_int, {}};
        seeds.push_back(seed);
    }
}

void Year2023_Day5::BuildSeeds_Ranged()
{
    seeds.clear();
    vector<string> seed_ints = SplitLineByToken(lines[0], ' ');
    seed_ints = {seed_ints.begin() + 1, seed_ints.end()};
    for(size_t i = 0; i < seed_ints.size(); i+=2)
    {
        /*
        const int64_t seed_int = strtoll(seed_ints[i].c_str(), nullptr, 10);
        const int64_t seed_range = strtoll(seed_ints[i + 1].c_str(), nullptr, 10);
        for(int64_t s = seed_int; s < seed_int + seed_range; s++)
        {
            Seed seed = {s, {}};
            seeds.push_back(seed);
        }*/
        const int64_t seed_int = strtoll(seed_ints[i].c_str(), nullptr, 10);
        const int64_t seed_range = strtoll(seed_ints[i + 1].c_str(), nullptr, 10);
        ranged_seeds.push_back({seed_int, seed_range});
    }
}

void Year2023_Day5::BuildConversionMaps()
{
    MapType parse_level = Default;
    auto r_map = new RangeBasedMap();
    
    const vector<string> chopped_lines = {lines.begin() + 2, lines.end()};
    for(const auto& line : chopped_lines)
    {
        if(line.empty())
        {
            conversion_maps[parse_level] = *r_map;
            r_map = new RangeBasedMap();
            continue;
        }
        
        if(!isdigit(line[0]))
        {
            parse_level = static_cast<MapType>(static_cast<int>(parse_level) + 1);
            continue;
        }

        vector<string> range = SplitLineByToken(line, ' ');

        Range r;
        r.destination_start = strtoll(range[0].c_str(), nullptr, 10);
        r.source_start = strtoll(range[1].c_str(), nullptr, 10);
        r.range_length = strtoll(range[2].c_str(), nullptr, 10);
        r_map->ranges.push_back(r);
    }
    conversion_maps[parse_level] = *r_map;
}

void Year2023_Day5::ConvertSeeds()
{
    for(auto& seed : seeds)
    {
        ConvertSeed(&seed);
    }
}

void Year2023_Day5::ConvertSeed(Seed* seed)
{
    for(const auto& seed_map : conversion_maps)
    {
        const MapType type = seed_map.first;
        RangeBasedMap r_map = seed_map.second;
        int64_t seed_value = seed->seed_num;
        if(type != SeedToSoil)
        {
            const auto prev_type = static_cast<MapType>(type - 1);
            const int64_t last_mapped_num = seed->mapped_values.at(prev_type);
            seed_value = last_mapped_num;
        }
        seed->mapped_values[type] = r_map.ConvertNumWithRange(seed_value); 
    }
}

void Year2023_Day5::ConvertRangedSeeds()
{
    /*
    for(const auto& ranged_seed : ranged_seeds)
    {
        
    }
    */
    for(const auto& seed_map : conversion_maps)
    {
        
    }
}

const Year2023_Day5::Seed* Year2023_Day5::GetSeedWithSmallestLocation()
{
    const Seed* min_seed = nullptr;
    int64_t min_seed_location = numeric_limits<int64_t>::max();
    
    for(const auto& seed : seeds)
    {
        const int64_t location = seed.mapped_values.at(HumidityToLocation);
        if(location < min_seed_location)
        {
            min_seed_location = location;
            min_seed = &seed;
        }
    }
    return min_seed;
}
