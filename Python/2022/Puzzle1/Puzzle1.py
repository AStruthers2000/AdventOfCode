# -*- coding: utf-8 -*-
"""
Created on Fri Dec  2 10:15:57 2022

@author: Andrew Struthers
"""

calories = []
with open("input.txt") as file:
    cur_sum = 0
    for line in file:
        if line == "\n":
            calories.append(cur_sum)
            cur_sum = 0
        else:
            cur_sum += int(line)
            
calories.sort()

print(f"The elf carrying the most Calories was carrying a total of {calories[-1]} Calories")
print(f"The three elves carying the most Calories have a combined {calories[-1]+calories[-2]+calories[-3]} Calories")