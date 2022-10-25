"""
7. Complete the following code (without using the replace function)-

def replace_comma_with_space(text):
    …
    …

s = "I,have,been,practising,python,since,the,course,started"
output = replace_comma_with_space(s)
print(output)
"""

def replace_comma_with_space(text : str) -> str:
    output = ""

    for char in text:
        if char == ',':
            output += ' '
        else:
            output += char

    return output


if __name__ == "__main__":

    s = "I,have,been,practising,python,since,the,course,started"
    
    output = replace_comma_with_space(s)
    
    print(output)