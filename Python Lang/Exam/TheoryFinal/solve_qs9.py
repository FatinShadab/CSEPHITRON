"""
    Run the below functions in 4 threads.

        >>> def f1():
        >>>     for i in range(5):
        >>>         print(f"f1 - {i}")
        >>> def f2():
        >>>     for i in range(5):
        >>>         print(f"f2 - {i}")
        >>> def f3():
        >>>     for i in range(5):
        >>>         print(f"f3 - {i}")
        >>> def f4():
        >>>     for i in range(5):
        >>>         print(f"f4 - {i}")
"""
from threading import Thread

def f1():
    for i in range(5):
        print(f"f1 - {i}")

def f2():
    for i in range(5):
        print(f"f2 - {i}")

def f3():
    for i in range(5):
        print(f"f3 - {i}")

def f4():
    for i in range(5):
        print(f"f4 - {i}")


if __name__ == "__main__":
    functions = [f1, f2, f3, f4]
    threads = [Thread(target=func) for func in functions]

    threads[0].start()
    threads[1].start()
    threads[2].start()
    threads[3].start()

    threads[0].join()
    threads[1].join()
    threads[2].join()
    threads[3].join()