n, p = 6, 4
posts = [0, 60, 120, 180, 240, 300]

# n, p = 5, 4
# posts = [0, 120, 180, 240, 270]

from itertools import combinations
from math import pi, sin

def sindeg(deg):
    return sin(deg * pi/180)

r = 1000
max_area = 0
best = None
for comb in combinations(posts, p):
    area = 0
    for i in range(0, p):
       area += 0.5 * r * r * sindeg((comb[(i+1)%p]-comb[i]) % 360)
    if (area > max_area):
        max_area = area
        best = comb
    
print(best)
print(max_area)
    

