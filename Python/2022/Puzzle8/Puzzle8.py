# -*- coding: utf-8 -*-
"""
Created on Wed Dec  7 21:11:02 2022

@author: Andrew Struthers

"""

trees = []

with open("input.txt") as file:
    for line in file:
        line = line.strip()
        
        line = [int(i) for i in line]
        trees.append(line)


rowMax = len(trees)
colMax = len(trees[0]) 
visibleCount = 0
highestScenicScore = -1

for x in range(len(trees)):
    for y in range(len(trees[0])):
        treeSlices = [[], [], [], []] #north, south, west, east
        for d in range(4):
            temp_x = x
            temp_y = y
            if d == 0:      #up
                while temp_x > 0:
                    treeSlices[d].append(trees[temp_x-1][y])
                    temp_x -= 1
            elif d == 1:    #down
                while temp_x + 1 < rowMax:
                    treeSlices[d].append(trees[temp_x+1][y])
                    temp_x += 1
            
            elif d == 2:    #left
                while temp_y > 0:
                    treeSlices[d].append(trees[x][temp_y-1])
                    temp_y -= 1
            
            elif d == 3:    #right
                while temp_y + 1 < colMax:
                    treeSlices[d].append(trees[x][temp_y+1])
                    temp_y += 1
        
        
        
        visible = [False for _ in range(len(treeSlices))]        
        visScore = [0,0,0,0]
        
        for i in range(len(treeSlices)):
            if len(treeSlices[i]) == 0:
                visible[i] = True
                visScore[i] += 1
            else:
                for tree in treeSlices[i]:
                    visScore[i] += 1
                    if tree >= trees[x][y]:
                        visible[i] = False
                        break
                    visible[i] = True
                
        if True in visible: 
            visibleCount += 1
        
        #print(f"Tree ({x}, {y}) = {trees[x][y]} has slices: {treeSlices} and scenic slices: {visScore}")
        vis = 1
        for score in visScore:
            vis *= score
        visScore = vis
        
        if visScore > highestScenicScore:
            highestScenicScore = visScore
            
        #print(f"Tree {trees[x][y]} is {'visible' if True in visible else 'not visibile'} with a visibility score of {visScore}")
                
    #print("=====")
print(f"The number of visible trees is {visibleCount}, and the highest scenic value is {highestScenicScore}")