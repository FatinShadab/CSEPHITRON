# 97 - 122 (smaller letters)
# 65 - 97  (capital letters)

def clean_string(text : str) -> str:
    output = ""

    for char in text:
        if ord(char) in range(65, 123):
            output += char

    return output


if __name__ == "__main__":
    s = "P::::::,,,,,h;;;;i,,,t--r;,:o..N"

    output = clean_string(s)

    print(output)