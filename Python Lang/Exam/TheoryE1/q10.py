"""
10. Write a Python class named Distance constructed by two 
    points (x1, y1), (x2, y2) and a method which will compute 
    the distance between those points.
"""
class Distance:
    def __init__(self, point1 : tuple, point2 : tuple) -> None:
        self.point1 = point1 
        self.point2 = point2 

        self.x1 = point1[0]
        self.y1 = point1[1]

        self.x2 = point2[0] 
        self.y2 = point2[1]

    def show(self) -> None:
        print(((self.x2 - self.x1)**2 + (self.y2 - self.y1)**2)**(1/2))


if __name__ == "__main__":
    x1 = 10
    y1 = 10

    x2 = 20
    y2 = 20
    d = Distance((10, 10), (20, 20))

    d.show()