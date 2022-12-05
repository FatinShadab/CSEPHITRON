"""
    You need to write a python program to take an integer input from the user and print a
    pattern given below

    When n=5,
        12345
        21345
        23145
        23415
        23451

    When n=7,
        1234567
        2134567
        2314567
        2341567
        2345167
        2345617
        2345671
"""

def pattern_diagonal1(n : int) -> None:
    for i in range(n):
        elements = [ele for ele in range(1, n+1)]
        ele = elements.pop(0)
        elements.insert(i, ele)
        print("".join(map(str, elements)))


if __name__ == "__main__":
    pattern_diagonal1(int(input()))