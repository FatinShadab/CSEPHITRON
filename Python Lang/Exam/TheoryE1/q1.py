"""
1. Create a function exp(a, n) that returns the exponential result ( an ). Read user input a and n 
in a single line from the keyboard.

Example input:
>> enter numbers: 2 3

Example Output:
>> result is: 8
"""
def exp(a : int, n : int) -> int:
    return a**n

if __name__ == "__main__":
    a, n = map(int, input("enter numbers: ").split())
    print(f"result is: {exp(a, n)}")