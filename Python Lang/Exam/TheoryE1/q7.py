"""
7. Write a Python class to get all possible unique subsets from a set of integers.

Input  : [4, 5, 6] 
Output : [[], [6], [5], [5, 6], [4], [4, 6], [4, 5], [4, 5, 6]]
"""
class Subsets:
    def __init__(self, numbers : list) -> None:
        self.numbers = numbers
        self.subsets = self.__make_subsets()

    def __make_subsets(self) -> list:
        subsets = [[]]

        for i in self.numbers:
            subsets += [subset + [i] for subset in subsets]

        return subsets

    def show(self) -> None:
        print(self.subsets)


if __name__ == "__main__":
    numbers = [4, 5, 6]

    numbers_subsets = Subsets(numbers)

    numbers_subsets.show()