num_tests = int(input())
for _ in range(num_tests):
    l1, b1, l2, b2, l3, b3 = map(int, input().split(" "))
    
    # three horizontal
    if l1 == l2 and l2 == l3 and b1 + b2 + b3 == l1:
        print("YES")
    # three vertical
    elif b1 == b2 and b2 == b3 and l1 + l2 + l3 == b1:
        print("YES")
    # vertical split
    elif b1 == b2 + b3 and l2 == l3 and l1 + l2 == b1:
        print("YES")
    # horizontal split
    elif l1 == l2 + l3 and b2 == b3 and b1  + b2 == l1:
        print("YES")
    else:
        print("NO")
