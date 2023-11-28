# -*- coding: utf-8 -*-
"""
Created on Fri Dec  2 10:30:35 2022

@author: Andrew Struthers
"""

score_dict = {
    "X": 1,
    "Y": 2,
    "Z": 3,
    }

choices = ["Rock", "Paper", "Scissors"]

"""
Part 1
Calculating the score by following the input guide exactly as written
"""
total_score = 0
with open("input.txt") as file:
    for line in file:
        score = 0
        
        op_choice = line.split(" ")[0].strip()
        my_choice = line.split(" ")[1].strip()
        
        op = ord(op_choice) - 65 
        my = ord(my_choice) - 88
        
        #print(f"Opponent chooses {choices[op]} so I will choose {choices[my]}")

        #they win, so my score increases only by what i cho0se
        if op - my == 1:
            score = score_dict[my_choice]
            
        elif op - my == -2:
            score = score_dict[my_choice]
        
        #i win, so my score increases by 6 (win) + what i choose
        elif op - my == -1:
            score = 6 + score_dict[my_choice]
            
        elif op - my == 2:
            score = 6 + score_dict[my_choice]
        
        #we tie, so my score increases by 3 (tie) + what i choose
        else:
            score = 3 + score_dict[my_choice]
        
        #print(f"My score for this round is {score}")
        total_score += score
        
print(f"My total score is {total_score}")

"""
Part 2
Calculating what choice I need to make to either win, lose, or draw according to the input guide
"""
total_score = 0
with open("input.txt") as file:
    for line in file:
        score = 0
        
        op_choice = line.split(" ")[0].strip()
        my_choice = line.split(" ")[1].strip()
        
        op = ord(op_choice) - 65
        my = ord(my_choice) - 88
        
        #i need to lose
        if my == 0:
            my_new = op - 1

        #i need to tie
        elif my == 1:
            my_new = op
            score += 3
            
        #i need to win
        else:
            my_new = op + 1
            score += 6
            
        if my_new > 2:
            my_new = 0
        if my_new < 0:
            my_new = 2
            
        #print(f"Opponent chooses {choices[op]} so I will choose {choices[my]}")
            
        my_new_choice = chr(my_new + 88)
        score += score_dict[my_new_choice]
        
        #print(f"My score for this round is {score}")
        total_score += score

print(f"My total score is {total_score}")
            