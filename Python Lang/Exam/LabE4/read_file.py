with open('words.dat', 'r') as f:
    words = [line.replace('\n', '') for line in f.readlines()]
    [print(f"{idx+1}: {word}") for idx, word in enumerate(words)]