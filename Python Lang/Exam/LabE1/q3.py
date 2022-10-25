"""
3. Go to this repo: https://pypi.org/project/pyjokes/ and try to make a chat bot to tell you joke
using pyjokes.

Write a function named tell_some_jokes() and write your code inside this function.
"""
import pyjokes

def tell_some_jokes() -> None:
    print(pyjokes.get_joke())

def chatbot() -> None:
    count = 0
    print("Hello, there I am a joke teller.")

    while True:
        if count < 1:
            cmd = input("Do you want to hear some jokes ? (y/n) - ")
        else:
            cmd = input("Do you want to hear some more jokes ? (y/n) - ")
        
        if cmd.lower() == 'y':
            tell_some_jokes()
            count += 1
        elif cmd.lower() == 'n':
            print("Ok, good bye then.")
            break
        else:
            print(f"{cmd} is't a valid response. please enter y/Y or n/N")


if __name__ == "__main__":
    chatbot()