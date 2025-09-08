def run():
    a, b = map(int, input().split())
    if a == b:
        return 0
    elif a % b == 0 or b % a == 0:
        return 1
    else:
        return 2

num_tests = int(input())
for _ in range(num_tests):
    print(run())
