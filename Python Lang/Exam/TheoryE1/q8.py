"""
8. Write a Python class to find a pair of elements 
(indices of the two numbers) from a given array whose sum 
equals a specific target number.

Input:
numbers=[10,20,10,40,50,60,70]
target=50

Output: 3, 4
"""
class ClassNotNeeded:
    def __init__(self, numbers : list, target : int) -> None:
        self.numbers = numbers
        self.target = target

    def show_pair(self) -> None:
        pair_idx1 = 0
        pair_idx2 = 0

        for idx, ele1 in enumerate(self.numbers):
            for ele2 in self.numbers[idx:]:
                if (ele1+ele2 == self.target):
                    pair_idx1 = idx
                    pair_idx2 = self.numbers.index(ele2)

        print(pair_idx1+1, pair_idx2+1)


if __name__ == "__main__":
    numbers = [10,20,10,40,50,60,70]
    target = 50 

    pair = ClassNotNeeded(numbers, target)

    pair.show_pair()