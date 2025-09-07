def run():
    a, b = map(int, input().split())
    if a % 2 == 0 and b % 2 == 0: # even even
        return a * b // 2 + 2
    elif a % 2 != 0 and b % 2 != 0: # odd odd
        return a * b + 1
    elif a % 2 == 0 and b % 2 != 0: # even odd
        return -1
    else: # odd even
        if b % 4 == 0: # divisible by four
            return a * b // 2 + 2
        else:
            return -1



num_tests = int(input())
for _ in range(num_tests):
    print(run())
