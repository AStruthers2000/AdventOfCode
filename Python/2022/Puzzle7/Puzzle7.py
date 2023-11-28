# -*- coding: utf-8 -*-
"""
Created on Tue Dec  6 21:20:08 2022

@author: Andrew Struthers
"""
        
class File:
    def __init__(self, name, parent=None, size=0, isFile=False):
        self.name = name
        self.parent = parent
        self.children = []
        self.files = []
        self.size = size
        self.isFile = isFile
    
    def UpdateSize(self, size):
        self.size += size
        if self.parent:
            self.parent.UpdateSize(size)
        
    def AddFile(self, file):
        self.files.append(file)
        self.UpdateSize(file.size)
    
root = File("/")
cwd = root

with open("input.txt") as file:
    for line in file:
        line = line.strip()
        
        linetype = line.split(" ")[0]
        
        if linetype == "$":
            command = line.split(" ")[1]
            if command == "cd":
                dest = line.split(" ")[2]
                if dest == "..":
                    cwd = cwd.parent
                else:
                    for folder in cwd.children:
                        if folder.name == dest:
                            cwd = folder
                            break
        elif linetype == "dir":
            name = line.split(" ")[1]
            cwd.children.append(File(name, cwd, False))
        else:
            size, name = line.split(" ")
            f = File(name, cwd, int(size), True)
            cwd.AddFile(f)
            
directorySum = 0
def CalculateSubdirectory(pwd):
    global directorySum
    if pwd.size <= 100000:
        directorySum += pwd.size
        
    for cwd in pwd.children:
        CalculateSubdirectory(cwd)
    
CalculateSubdirectory(root)
print(f"The sum of the total sizes of the directories with at most size = 100,000 is {directorySum}\n\n")

totalSpace = 70000000
need = 30000000
used = root.size
mustDelete = need - (totalSpace - used)
print(f"Total space:     {totalSpace}\nUsed space:      {used}\nRemaining space: {totalSpace - used}\n\nThe size of the update is {need}, please delete {mustDelete}\n")

smallestDir = totalSpace
def FindDeleteFolder(pwd):
    global smallestDir
    if pwd.size >= mustDelete and pwd.size < smallestDir:
        smallestDir = pwd.size
        
    for cwd in pwd.children:
        FindDeleteFolder(cwd)
        
FindDeleteFolder(root)
print(f">The total size of the smallest directory that, if deleted, would free up enough space is {smallestDir}")