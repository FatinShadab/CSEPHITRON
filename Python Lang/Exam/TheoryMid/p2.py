"""
2. Write a program center_align.py to 
centre align all lines in the given file.
"""
import os

fpath = input().replace('\\', '/')

if os.path.isfile(fpath):
    with open(fpath, 'r') as f:
        lines = f.readlines()

    with open(fpath, 'w') as f:
        for line in lines:
            center_line = line[:len(line)-4].center(100)+'\n'
            print(center_line)
            f.write(center_line)

else:
    print(f"Invalid path! : {fpath}")