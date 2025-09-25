from collections import Counter

brackets = input()
counter = Counter(list(brackets))
if counter['('] == counter[')']:
    lastIndex = len(brackets) - 1 - brackets[::-1].index(")")
    for i, c in enumerate(brackets):
        if c == "(" and i > lastIndex:
            print("No")
            break
    else:
        print("Yes")
else:
    print("No")

