#pragma once
#include <map>

#include "../../Problem.h"

class Year2023_Day5 : public Problem
{
public:
    Year2023_Day5() : Problem("Year 2023 Day 5: If You Give A Seed A Fertilizer")
    {
        filepath = R"(./2023/Day5/)";
    }

    string Problem1() override;
    string Problem2() override;

private:
    enum MapType
    {
        Default = 0,
        SeedToSoil,
        SoilToFertilizer,
        FertilizerToWater,
        WaterToLight,
        LightToTemperature,
        TemperatureToHumidity,
        HumidityToLocation
    };
    
    struct Seed
    {
        int64_t seed_num;
        map<MapType, int64_t> mapped_values = {}; 
    };

    struct RangedSeedGroup
    {
        int64_t range_start = 0;
        int64_t range_length = 0;

        Seed start_of_range_seed;
    };

    struct Range
    {
        int64_t destination_start = 0;
        int64_t source_start = 0;
        int64_t range_length = 0;
    };
    
    struct RangeBasedMap
    {
        vector<Range> ranges;

        int64_t ConvertNumWithRange(const int64_t num)
        {
            for(const auto& r : ranges)
            {
                if(num >= r.source_start && num < r.source_start + r.range_length)
                {
                    const int64_t offset = r.source_start - r.destination_start;
                    return num - offset;
                }
            }
            return num;
        }
    };
    
    map<MapType, RangeBasedMap> conversion_maps;
    vector<Seed> seeds;
    vector<RangedSeedGroup> ranged_seeds;

    void BuildSeeds_Standard();
    void BuildSeeds_Ranged();
    void BuildConversionMaps();
    void ConvertSeeds();
    void ConvertSeed(Seed* seed);
    void ConvertRangedSeeds();
    void 

    const Seed* GetSeedWithSmallestLocation();
};