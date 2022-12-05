"""
    Write a python program to make the data given below using list and dictionary
    comprehension and print it.
    
    data = {
        1 : [2,3,4,5],
        2 : [1,3,4,5],
        3 : [1,2,4,5],
        4 : [1,2,3,5],
        5 : [1,2,3,4]
    }
"""
if __name__ == "__main__":
    data = {key : [ele for ele in range(1, 6) if ele != key] for key in range(1, 6)}
    print(data)