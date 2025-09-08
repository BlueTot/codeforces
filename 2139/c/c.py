def run():
    n, x = map(int, input().split())
    low = 1
    high = (1<<(n+1))-1
    num_steps = 0 
    steps = [] 
    while True:
        mid = (low + high) // 2
        if mid == x:
            return num_steps, steps
        elif x < mid:
            high = mid - 1
            steps.append("left")
        else:
            low = mid + 1
            steps.append("right")
        num_steps += 1

num_tests = int(input())
for _ in range(num_tests):
    num_steps, steps = run()
    print(num_steps)
    print(" ".join(["1" if step == "left" else "2" for step in reversed(steps)]))
