# -*- coding: utf-8 -*-
"""
Created on Mon Dec  5 10:36:55 2022

@author: Andrew Struthers

"""
def GenerateStack(line, stacks):
    parts = [line[i:i+3] for i in range(0, len(line), 4)]
    for i in range(len(parts)):
        if parts[i][0] == '[':
            try:
                stacks[i].append(parts[i])
            except IndexError:
                for j in range(len(stacks), i):
                    stacks.append([])
                stacks.append([parts[i]])

                
def SimpleMove(line, stacks):
    moveAmount = int(line[1])
    moveSource = int(line[3]) - 1
    moveDest = int(line[5]) - 1
    
    for i in range(moveAmount):
        moveBox = stacks[moveSource][0]
        stacks[moveSource].remove(moveBox)
        stacks[moveDest].insert(0, moveBox)
        

def ComplexMove(line, stacks):
    moveAmount = int(line[1])
    moveSource = int(line[3]) - 1
    moveDest = int(line[5]) - 1
    
    if moveAmount == 1:
        SimpleMove(line, stacks)
    else:
        stackSlice = stacks[moveSource][0:moveAmount]
        newIndex = 0
        for crate in stackSlice:
            stacks[moveSource].remove(crate)
            stacks[moveDest].insert(newIndex, crate)
            newIndex += 1
        

def FindTopCrates(stacks):
    topCrates = ""
    for i in range(len(stacks)):
        topCrate = stacks[i][0][1:2]
        topCrates += topCrate
    return topCrates
                

stacks_pt1 = [[]]
stacks_pt2 = []
generatingStacks = True

with open("input.txt") as file:
    for line in file:
        if " 1   2 " in line:
            generatingStacks = False
            
        if generatingStacks:
            GenerateStack(line, stacks_pt1)
            GenerateStack(line, stacks_pt2)
            
        else:
            line = line.strip().split(' ')
            if line[0] == "move":
                SimpleMove(line, stacks_pt1)
                ComplexMove(line, stacks_pt2)

print(f"The crates on the top of each stack with the CrateMover 9000 are {FindTopCrates(stacks_pt1)}")
print(f"The crates on the top of each stack with the CrateMover 9001 are {FindTopCrates(stacks_pt2)}")
