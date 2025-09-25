def win(n) -> bool:
    return (n + 1) & n != 0

num_tests = int(input())
for _ in range(num_tests):
    n = int(input())
    print("First" if win(n) else "Second")
