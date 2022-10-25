"""
9. You need to make a positive story into a negative by changing some of its words
automatically. Someone gave you a list `replace with’ and asked to find the words that are in
that list in string ‘s’ and replace them with the next word of that list.

replace_with = ["chief", "thief", "superintendent", "sweeper",
"married", "left", "tried", "died"]

s = "I am the chief of Baghdad. Before that I used to be a
superintendent of Bank Asia. Things have changed a lot since Jorina
married me. A lot of girls tried to marry me."

Output example (one done for you):
"I am the thief of Baghdad..........."

Write a function named replace_word() and write your code inside this function.
"""

def replace_word() -> None:
    replace_with = ["chief", "thief", "superintendent", "sweeper", "married", "left", "tried", "died"]

    s = "I am the chief of Baghdad. Before that I used to be a superintendent of Bank Asia. Things have changed a lot since Jorina married me. A lot of girls tried to marry me."
    
    words = s.split(" ")

    for idx, word in enumerate(words):
        if word in replace_with:
            word_idx = replace_with.index(word)
            if word_idx%2 == 0:
                words[idx] = replace_with[word_idx+1]
    
    print(" ".join(words))


if __name__ == "__main__":
    replace_word()