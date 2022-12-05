"""
    You need to slice the list with values which are divided by 3. The list is given below,
    lst = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]
    Output: [3, 6, 9, 12, 15, 18]
"""
if __name__ == "__main__":
    lst = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]
    lst = list(filter(lambda x: x % 3 == 0, lst))
    print(lst)