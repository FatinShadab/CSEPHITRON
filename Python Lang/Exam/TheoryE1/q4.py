"""
4. Write a python program for the requirement below. Notice 
the output must be in sorted order -

Input  : x3b4U5i2
Output : bbbbiiUUUUUxxx
"""
def generate_string(code : str) -> str:
    chars = dict({})

    for idx, char in enumerate(code):
        if ord(char) in range(48, 58):
            chars[code[idx-1].lower()] = code[idx-1]*int(char)

    return "".join([chars[key] for key in sorted(chars.keys())])


if __name__ == "__main__":
    code = "x3b4U5i2"

    string = generate_string(code)
    
    print(string)