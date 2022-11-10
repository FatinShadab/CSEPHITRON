"""
Write a program to display a simple form of digital book. “Books” are text files in which each
block (page) of text is followed by a double dash (--). When a book is displayed, the first block of
text is shown and the program should wait for the user to press the enter key before displaying
the next.

File.txt:
This is first page content--Now we are in the second pageq
Output:
This is first page content
[enter - read more, press q to quit]
"""
import os

fpath = input("Enter the file path: ").replace('\\', '/')

if os.path.isfile(fpath):
    pages = []

    with open(fpath, "r") as book:
        content = book.readlines()
    
    for page in content:
        for p in page.replace('\n', "").split("--"):
            pages.append(p)

    idx = 0
    while True:
        if idx > len(pages)-1:
            input("Book content finshed, enter to quit ")
            break

        print(pages[idx])
        idx += 1
        
        ucmd = input("[enter - read more, press q to quit] : ")

        if ucmd.lower() == 'q':
            break

else:
    print(f"Invalid path! : {fpath}")