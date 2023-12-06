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

        RangedSeedGroup(const int64_t start, const int64_t length)
        {
            range_start = start;
            range_length = length;
            start_of_range_seed = {range_start, {}};
        }
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

        vector<RangedSeedGroup> SplitRangedSeedByRanges(const RangedSeedGroup& range)
        {
            std::vector<RangedSeedGroup> result;

            int64_t current_start = range.range_start;
            int64_t remaining_length = range.range_length;
            const int64_t current_end = current_start + remaining_length - 1;
            
            for (const auto& split_range : ranges) {
                const int64_t range_start = split_range.source_start;
                const int64_t range_end = split_range.source_start + split_range.range_length - 1;
                
                const int64_t overlap_start = max(current_start, range_start);
                const int64_t overlap_end = min(current_end,range_end);

                if (overlap_start < overlap_end)
                {
                    //cout << "Overlap detected between range [" << current_start << ", " << current_end << "] and range ["
                     //                                          << range_start << ", " << range_end << "]" << endl;
                    //cout << "\tOverlap start: " << overlap_start << ", and overlap end: " << overlap_end << endl;
                    result.emplace_back(ConvertNumWithRange(overlap_start), overlap_end - overlap_start + 1);
                    current_start = overlap_end + 1;
                    remaining_length -= overlap_end - overlap_start + 1;
                }

                
                if (current_start >= range.range_start + range.range_length - 1)
                {
                    break;
                }
            }

            
            if (remaining_length > 0)
            {
                result.emplace_back(current_start, remaining_length);
            }

            return result;
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

    const Seed* GetSeedWithSmallestLocation();
};