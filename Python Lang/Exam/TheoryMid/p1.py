"""
1. We can read 'abba' if we reverse the letters, 
it’s still 'abba', so this string is called palindrome. 
Write a python program to check if a string is palindrome or not. 
"""

user_input = input()

if user_input == user_input[::-1]:
    print(f"{user_input} is a palindrome.")
else:
    print(f"{user_input} is not a palindrome.")