"""
9. Write a class with two instance variables X, n . Add two 
methods sum() and pow() to get the sum of X+n and exponential/
power of X^n .
"""
class Myint:
    def __init__(self, data : int) -> None:
        self.data = data

    def __add__(self, other) -> 'Myint':
        return Myint(self.data + other.data)

    def __pow__(self, other) -> 'Myint':
        return Myint(self.data ** other.data)

    def sum(self, other : 'Myint') -> int:
        return (self + other).data

    def pow(self, other : 'Myint') -> int:
        return (self ** other).data

if __name__ == "__main__":
    x = Myint(3)
    n = Myint(2)

    print(f"x : {x.data}\nn : {n.data}\nx + n = {x.sum(n)}\nx ^ n = {x.pow(n)}")