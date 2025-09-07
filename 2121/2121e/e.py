from functools import lru_cache

num_tests = int(input())

def score(x, l, r):
    if x == l and x == r:
        return 2
    elif x == l and x!= r or x != l and x == r:
        return 1
    else:
        return 0


def log(func):
    def wrapper(arg1, arg2, arg3, arg4):
        result = func(arg1, arg2, arg3, arg4)
        print(f"{arg1}, {arg2}, {arg3}, {arg4} => {result}")
        return result
    return wrapper


# @log
@lru_cache
def minf(l: str, r: str, origl:str, origr: str) -> float:

    if not l and not r:
        return 0

    l0, r0 = int(l[0]), int(r[0])

    if l0 == r0:
        return score(l0, int(origl[0]), int(origr[0])) + minf(l[1:], r[1:], origl[1:], origr[1:])

    smallest = float("inf")

    # f = l0
    digit_cost = score(l0, int(origl[0]), int(origr[0]))
    rem = minf(l[1:], "9"*(len(l)-1), origl[1:], origr[1:])
    smallest = min(smallest, digit_cost + rem)

    # in between
    rem = minf("0"*(len(l)-1), "9"*(len(r)-1), origl[1:], origr[1:])
    for f in range(l0+1, r0):
        digit_cost = score(f, int(origl[0]), int(origr[0]))
        smallest = min(smallest, digit_cost + rem)

    # f = r0
    digit_cost = score(r0, int(origl[0]), int(origr[0]))
    rem = minf("0"*(len(r)-1), r[1:], origl[1:], origr[1:])
    smallest = min(smallest, digit_cost + rem)

    return smallest


for _ in range(num_tests):
    l, r = map(int, input().split(" "))
    print(minf(str(l), str(r), str(l), str(r)))
    
