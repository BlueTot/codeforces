def run():
    n, a, b = map(int, input().split())

    if a <= b:
        return b % 2 == n % 2
    else:
        return a % 2 == n % 2 and b % 2 == n % 2


num_tests = int(input())

for _ in range(num_tests):
    if run():
        print("YES")
    else:
        print("NO")
