def run():
    n = int(input())
    a = list(map(int, input().split()))
    count = 0

    # pairs
    for i in range(n-1):
        if i % 2 == 0: # first is odd, second is even
            if a[i] > a[i+1]:
                count += a[i] - a[i+1]
                a[i] = a[i+1]
        else: # first is even, second is odd
            if a[i] < a[i+1]:
                count += a[i+1] - a[i]
                a[i+1] = a[i]

    # triplets
    for i in range(0, n-2, 2):
        if a[i] + a[i+2] > a[i+1]:
            count += (diff := a[i] + a[i+2] - a[i+1])
            if a[i+2] > 0 and a[i] > 0:
                a[i+2] -= diff
            elif a[i+2] > a[i]:
                a[i+2] -= diff
            else:
                a[i] -= diff

    # print(a)
    return count

num_tests = int(input())
for _ in range(num_tests):
    print(run())
