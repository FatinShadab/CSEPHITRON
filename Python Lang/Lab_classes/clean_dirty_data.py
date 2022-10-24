"""
Clean the data and get a string output containintg only 'a e i o u'

means, 
    we will output the lower vowel alphabets from the inputed data and have to make a new
    string containing all those space separated.

Test case:
Input: "aNtEriOur\n\t>>"       Output: "a e i o u"
"""

data = "aNtEriOur\n\t>>"

print(f"Data before cleaning - {data}")

data = "".join([(char+' ') for char in data.lower() if char in ('a', 'e', 'i', 'o', 'u')]).rstrip()

print(f"Data after cleaning - {data}")