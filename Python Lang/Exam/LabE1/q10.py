"""
10. Given a string ‘s’ you need to find the words that are in list ‘a’ and use the next words on
string ‘s’ to create a new string. Save it inside a file called ‘out.txt’. Remember to close the
file after writing.
Write a function named create_new_string() and write your code inside this function.
Example:

a = ['oh', 'Emelia', 'to']

s = "Oh, I got two tickets for Dhaka. I and Emelia love to visit
different places very much. This time we are going to Bangladesh."

output = "I love visit Bangladesh" (inside a file)
"""

def create_new_string() -> None:
    a = ['oh', 'Emelia', 'to']
    a = [word.lower() for word in a]

    s = "Oh, I , got two tickets for Dhaka. I and Emelia love to visit different places very much. This time we are going to Bangladesh."
    words = s.split(" ")

    new_string_words = []
    for idx, word in enumerate(words):
        for char in word:
            if ord(char) not in range(65, 123):
                words[idx] = word.replace(char, "")

    for idx, word in enumerate(words):
        if word.lower() in a:
            new_string_words.append(words[idx+1])


    print(" ".join(new_string_words))

    with open("out.txt", 'w') as f:
        f.write(" ".join(new_string_words))


if __name__ == "__main__":
    create_new_string()