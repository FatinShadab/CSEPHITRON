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


Extend the challenge so that it is possible to skip forward by an arbitrary number of
pages. This should be achieved by allowing the user to enter a number before pressing the
enter key. If the number is positive, the given number of pages are skipped. If there is no
number, the next page is displayed.

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
       
        ucmd = input("[enter - read more, press q to quit] : ")
 
        if ucmd.isalnum():
            if 0 < int(ucmd) < len(pages) :
                idx += int(ucmd)
            elif int(ucmd) >= len(pages):
                idx = len(pages)-1
            else:
                idx += 1
 
        elif ucmd.lower() == 'q':
            break
 
        else:
            idx += 1
else:
    print(f"Invalid path! : {fpath}")