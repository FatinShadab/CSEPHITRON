"""
Conver recursive functions into iterative ones.
"""
# NO 1:
def sum_odd(n : int, total : int) -> int:
    if n == 1: return total
    elif n % 2 == 0: return sum_odd(n-1, total)
    else : return sum_odd(n - 2, total + n)

def sum_odd_using_loop(n : int, total : int) -> int:
    while (n > 1):
        if n%2 == 0 : n -= 1
        total += n
        n -= 2
    return total

# NO 2:
def _max(l : list or tuple or str or set, n : int) -> int:
    if l == [] : return n
    elif l[0] > n : return _max(l[1:], l[0])
    else: return _max (l[1:], n)

def _max_using_loop(l : list or tuple or str or set, n : int) -> int:
    while l:
        if l[0] > n:
            n = l[0]
        l = l[1:]
    return n

# NO 3:
def mylen(l : list or tuple or str or set, n : int) -> int:
    if l == [] : return n
    else : return mylen(l[1:], n+1)

def mylen_using_loop(l : list or tuple or str or set, n : int) -> int:
    while l:
        n += 1
        l = l[1:]
    return n

if __name__ == "__main__":
    print("# NO: 1")
    print(f"\twith recursive  : {sum_odd(10, 1)}")
    print(f"\twith while loop : {sum_odd_using_loop(10, 1)}")

    print("# NO: 2")
    print(f"\twith recursive  : {_max([10, 20, 30, 40, 50], 0)}")
    print(f"\twith while loop : {_max_using_loop([10, 20, 30, 40, 50], 0)}")

    print("# NO: 3")
    print(f"\twith recursive  : {mylen([10, 20, 30, 40, 50], 0)}")
    print(f"\twith while loop : {mylen_using_loop([10, 20, 30, 40, 50], 0)}")