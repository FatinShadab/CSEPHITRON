import unittest


def half_adder(a : int, b : int) -> dict:
    return {'sum':a^b, 'carry':a&b} if a*b in (0, 1) and len(str(a))*len(str(b)) == 1 else exec('raise ValueError("a and b must be binary 0 | 1")')


class Testing(unittest.TestCase):
    __test_0_0_inputs = (0, 0)
    __test_0_0_output = {'sum':0, 'carry':0}

    __test_0_1_inputs = (0, 1)
    __test_0_1_output = {'sum':1, 'carry':0}

    __test_1_0_inputs = (1, 0)
    __test_1_0_output = {'sum':1, 'carry':0}

    __test_1_1_inputs = (1, 1)
    __test_1_1_output = {'sum':0, 'carry':1}

    __test_invalid_inputs = ((101, 111), (0, 101), (12, 99), (0, 100))
    __test_invalid_output = ValueError

    def test_0_0(self) -> None:
        a, b = self.__test_0_0_inputs
        self.assertEqual(self.__test_0_0_output, half_adder(a, b))

    def test_0_1(self) -> None:
        a, b = self.__test_0_1_inputs
        self.assertEqual(self.__test_0_1_output, half_adder(a, b))

    def test_1_0(self) -> None:
        a, b = self.__test_1_0_inputs
        self.assertEqual(self.__test_1_0_output, half_adder(a, b))

    def test_1_1(self) -> None:
        a, b = self.__test_1_1_inputs
        self.assertEqual(self.__test_1_1_output, half_adder(a, b))

    def test_invalid(self):
        for inputs in self.__test_invalid_inputs:
            a, b = inputs
            with self.assertRaises(self.__test_invalid_output) as error:
                try:
                    half_adder(a, b)
                except self.__test_invalid_output as e:
                    print(f"\n for input a: {a}, b: {b}, Error : {self.__test_invalid_output} : {e}")
                    raise e


if __name__ == "__main__":
    unittest.main()