"""
4. Write a program to find anagrams in a given list of words. Two words are called anagrams if
one word can be formed by rearranging letters of another. For example ‘eat’, ‘ate’ and ‘tea’ are
anagrams.
>>> anagrams(['eat', 'ate', 'done', 'tea', 'soup', 'node'])
[['eat', 'ate', 'tea], ['done', 'node'], ['soup']]
"""

def anagrams(strings : list) -> list[list]:
    output = []
    checked = []

    for string in strings:
        if string not in checked:
            lst = []
            for string2 in strings:
                is_anagrams = True
                for ch in string:
                    if ch not in string2:
                        is_anagrams = False
                        break
                if is_anagrams:
                    lst.append(string2)
                    checked.append(string2)
            output.append(lst)

    return output

if __name__ == "__main__":
    an = anagrams(['eat', 'ate', 'done', 'tea', 'soup', 'node'])
    print(an)