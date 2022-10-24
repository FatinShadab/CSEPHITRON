"""
Chatbot.

    steps:
        1. Input/listen
        2. process/decide
        3. output/talkback
"""

def listen() -> str:
    return input("Say something : ")

def decide(cmd : str) -> None:
    logic = {
        "greetings" : ("hi", "hello", "hey", "yo"),
        "bye_words" : ("bye", "tata", "hasta la vista")
    }

    cmd_chanks = cmd.lower().split(" ")

    for chank in cmd_chanks:
        if chank in logic["greetings"]:
            talkback("Hello there.")
            break

        elif chank in logic["bye_words"]:
            talkback("Please turn me off before leaving")
            break

def talkback(response : str) -> None:
    print(response)
    pass

    

if __name__ == "__main__":
    while True:
        cmd = listen()
        decide(cmd)