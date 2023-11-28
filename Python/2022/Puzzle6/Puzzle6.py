# -*- coding: utf-8 -*-
"""
Created on Mon Dec  5 21:13:08 2022

@author: Andrew Struthers
"""

def CountChar(string, char):
    charCount = 0
    for i in string:
        if i == char:
            charCount += 1
    return charCount

char_lengths = [4, 14]
start_type = ["Start-of-Packet", "Start-of-Message"]

for length in char_lengths:
    with open("input.txt") as file:
        line = file.readline()
        #line = line.split()
        
        marker = 0
        SoP_found = False
        for i in line:
            if marker > length - 1:
                subsection = line[marker-length:marker]
                charCount = [CountChar(subsection, j) for j in subsection]
                
                if sum(charCount) == length:
                    SoP_found = True
                
            if SoP_found:
                break
            else:
                marker += 1
    
    print(f"The first {start_type[char_lengths.index(length)]} marker is at position: {marker}")