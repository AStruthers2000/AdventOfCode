# -*- coding: utf-8 -*-
"""
Created on Sat Dec  3 21:15:28 2022

@author: Andrew Struthers
"""

class Assignment():
    def __init__(self, section):
        self.l = int(section.split("-")[0])
        self.h = int(section.split("-")[1])
    
    def AssignmentInside(self, other):
        if self.l <= other.l:
            if self.h >= other.h:
                return True
        return False
    
    def AssignemtnOverlap(self, other):
        
        if self.h >= other.l:
            if other.h >= self.l:
                return True
        return False


contain_count = 0
overlap_count = 0

with open("input.txt") as file:
    for line in file:
        assignment = line.strip()
        
        sect1 = Assignment(assignment.split(",")[0])
        sect2 = Assignment(assignment.split(",")[1])
        
        if sect1.AssignmentInside(sect2) or sect2.AssignmentInside(sect1):
            contain_count += 1
            
        if sect1.AssignemtnOverlap(sect2) or sect2.AssignemtnOverlap(sect1):
            overlap_count += 1

print(f"There are a total of {contain_count} assignments with a range that contains the other")
print(f"There are a total of {overlap_count} assignments with a range that overlaps the other")
