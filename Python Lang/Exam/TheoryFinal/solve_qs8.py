"""
    You need to write a python lambda function to tell whether a number is even or not. If it
    is even, return “Yes” otherwise “No”.
    
    Code:
        >>> print(even_odd(5))
    
    Output:
        No
"""
even_odd = lambda x : "Yes" if x % 2 == 0 else "No"


if __name__ == "__main__":
    print(even_odd(5))