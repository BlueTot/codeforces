n = int(input())
array = list(map(int, input().split()))
q = int(input())

for _ in range(q):
    query = list(map(int, input().split()))
    if query[0] == 1:
        i, val = query[1] - 1, query[2]
        array[i] = val
    else:
        i = query[1] - 1
        for j, x in enumerate(array):
            if abs((i - j) ** 3) >= x:
                print(j + 1)
                break
        else:
            print(-1)
