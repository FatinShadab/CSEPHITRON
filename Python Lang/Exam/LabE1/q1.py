"""
1. Create a string out of some words given in a list -

l = ["This", "is", "very", "fantastic"]

Expected Output:

"This is very fantastic"

Write a function named create_string() and write your code inside this function.
"""

def create_string() -> None:
    words = ["This", "is", "very", "fantastic"]
    sentence = " ".join(words)
    print(sentence)


if __name__ == "__main__":
    create_string()