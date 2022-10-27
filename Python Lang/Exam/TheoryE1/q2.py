"""
2. Write a python to read three floating numbers from the 
keyboard in a single line with ‘-’ (dash) in between and output
their sum.

Example input:
>> enter numbers: 2.3-4.5-1.7

Example Output:
>> sum is: 8.5
"""
if __name__ == "__main__":
    x, y, z = map(float, input("enter numbers: ").split('-'))
    print(f"sum is: {x+y+z}")