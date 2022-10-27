"""
3. Write a python program to reverse every word from a given 
string s and output a new string. The position of words will 
remain the same, but their contents will be in reverse order.

s = “Programming Hero is the best”

Expected output: “gnimmargorP oreH si eht tseb”
"""
def reverse_string(string : str) -> str:
    words = []

    for word in string.split():
        words.append(word[::-1])

    return " ".join(words)

if __name__ == "__main__":
    s = "Programming Hero is the best"

    new_string = reverse_string(s)

    print(new_string)
