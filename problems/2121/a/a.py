num_tests = int(input())

def task():
    n, s = list(map(int, input().split(" ")))
    xs = list(map(int, input().split(" ")))
    smallest, largest = min(xs), max(xs)
    if smallest == largest:
        return abs(s - smallest)
    else:
        return (largest - smallest) + min(abs(s - smallest), abs(largest - s))

for _ in range(num_tests):
    print(task())
