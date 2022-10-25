"""
8. Suppose you have a program that converts a string into Upper, Capitalized and Lower
style using three different functions. Now create a test script for testing the three functionality
of that program. Run using PyTest.

    a. Write a function make_upper() to make the string in uppercase
    b. Write a function make_capital() to make the string capitalized
    c. Write a function make_lower() to make the string lowercase

Write a function named test_script() and write your code inside this function.
"""
import os
import sys 
import pytest

def make_upper(word : str) -> str:
    return word.upper()

def make_capital(word : str) -> str:
    return word.capitalize()

def make_lower(word : str) -> str:
    return word.lower()

def test_script() -> None:
    # All correct tests
    assert make_upper("hello") == "HELLO"
    assert make_capital("hello") == "Hello"
    assert make_lower("HELLO") == "hello"

    # One Incorrect test
    assert make_lower("HELLO") == "hellO"


if __name__ == "__main__":
    os.system(f"pytest -v {sys.argv[0]}")