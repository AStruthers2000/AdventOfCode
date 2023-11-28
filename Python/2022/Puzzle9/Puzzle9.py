# -*- coding: utf-8 -*-
"""
Created on Fri Dec  9 11:58:51 2022

@author: Andrew Struthers
"""

x_r = 0; x_l = 0; y_u = 0; y_d = 0
moves = []
with open("input.txt") as file:
    for line in file:
        d, n = line.split(" ")
        n = int(n)
        
        moves.append([d, n])
        
        if d == "R":
            x_r += n
        elif d == "L":
            x_l += n
        elif d == "U":
            y_u += n
        elif d == "D":
            y_d += n
        
#grid = [[0 for _ in range((x_r+x_l)*2)] for _ in range((y_u+y_d)*2)]
spots = [['.' for _ in range((x_r+x_l)*2)] for _ in range((y_u+y_d)*2)]
head_pos = [int(len(spots[0])/2), int(len(spots)/2)]
tail_pos = [int(len(spots[0])/2), int(len(spots)/2)]

spots[head_pos[1]][head_pos[0]] = 's'

def PrintGrid(grid):
    string = ""
    for y in range(len(grid)):
        for x in range(len(grid[0])):
            if x == head_pos[0] and y == head_pos[1]:
                string += 'H'
            elif x == tail_pos[0] and y == tail_pos[1]:
                string += 'T'
            else:
                string += spots[y][x]
                
        string += "\n"
    print(string)
    return

import math
print("== Initial State ==")
#PrintGrid(spots)
for move in moves:
    d, n = move
    print(f"== {d} {n} ==")
    for _ in range(n):
        if d == "R":
            head_pos[0] += 1
        if d == "L":
            head_pos[0] -= 1
        if d == "U":
            head_pos[1] -= 1
        if d == "D":
            head_pos[1] += 1
            
        dist = math.sqrt(abs(head_pos[0] - tail_pos[0])**2 + abs(head_pos[1] - tail_pos[1])**2)
        if dist == 2:
            if d == "R":
                tail_pos[0] += 1
            if d == "L":
                tail_pos[0] -= 1
            if d == "U":
                tail_pos[1] -= 1
            if d == "D":
                tail_pos[1] += 1
        elif dist == math.sqrt(5):
            x_dist = head_pos[0] - tail_pos[0]
            y_dist = head_pos[1] - tail_pos[1]
            
            if y_dist == -2:
                tail_pos[0] = head_pos[0]
                tail_pos[1] -= 1
            elif y_dist == 2:
                tail_pos[0] = head_pos[0]
                tail_pos[1] += 1
            elif x_dist == 2:
                tail_pos[1] = head_pos[1]
                tail_pos[0] += 1
            else:
                tail_pos[1] = head_pos[1]
                tail_pos[0] -= 1
                
        spots [tail_pos[1]][tail_pos[0]] = '#'
        #PrintGrid(spots)
        #print("====="*5)
    
tail_pos_count = 0
for y in range(len(spots)):
    for x in range(len(spots[y])):
        if spots[y][x] == '#':
            tail_pos_count += 1
        

print(f"The tail has visited {tail_pos_count} unique spots")
