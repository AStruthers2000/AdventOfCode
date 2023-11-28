# -*- coding: utf-8 -*-
"""
Created on Sat Dec  3 20:50:22 2022

@author: Andrew Struthers
"""

def calc_priority(c):
    p = ord(c) - 96
    if p < 0:
        p += 58
    return p

priority_sum = 0
with open("input.txt") as file:
    
    for line in file:
        rucksack = line.strip()
        
        comp1 = rucksack[:int(len(rucksack)/2)]
        comp2 = rucksack[int(len(rucksack)/2):]

        #print(f"{rucksack} splits into {comp1} and {comp2}")
        
        match = ''
        
        for i in comp1:
            for j in comp2:
                if i == j:
                    match = i
                    
        if match == "":
            print("No match in this rucksack")
        else:
            priority = calc_priority(match)
            priority_sum += priority
            
print(f"The sum of all priorities of matching items is: {priority_sum}")


priority_sum = 0
with open("input.txt") as file:
    group_rucksacks = []
    for line in file:
        group_rucksacks.append(line.strip())
        
        if len(group_rucksacks) == 3:
            match = ''
            for i in group_rucksacks[0]:
                for j in group_rucksacks[1]:
                    for k in group_rucksacks[2]:
                        if i == j and j == k:
                            match = i
            
            priority = calc_priority(match)
            priority_sum += priority
            group_rucksacks.clear()

print(f"The sum of all priorities of group badges is: {priority_sum}")
        
        