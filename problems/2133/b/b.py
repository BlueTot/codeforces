def run():
    n = int(input())
    grumpiness = list(map(int, input().split()))
    
    grumpiness.sort(reverse=True)
    total = 0
    for i in range(len(grumpiness)):
        if i % 2 == 0:
            total += grumpiness[i]
    return total


num_tests = int(input())
for _ in range(num_tests):
    print(run())
