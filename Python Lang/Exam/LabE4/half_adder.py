"""
Half adder is a combinational logic circuit which is mainly used for summation of 
2 digits (1-bite each) and it returns 2 outputs one is the sum and one is the carry.
Half adder is the combination of AND and X-OR gate. The X-OR gate is used for getting 
the sum and the AND gate is responsible for the carry output.
"""

def half_adder(a : int, b : int) -> dict:
    return {'sum':a^b, 'carry':a&b} if a*b in (0, 1) else exec('raise ValueError("a and b must be binary 0 | 1")')

if __name__ == "__main__":
    _sum, carry = half_adder(1, 1).values()
    print(f"Sum: {_sum},  carray: {carry}")