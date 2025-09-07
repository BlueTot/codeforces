num_tests = int(input())

for _ in range(num_tests):
    num = int(input())
    digits = set(map(int, str(num)))
    print(min(digits))
