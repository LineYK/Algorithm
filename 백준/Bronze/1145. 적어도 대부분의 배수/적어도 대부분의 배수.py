import sys
import math
from itertools import combinations

nums = list(map(int, sys.stdin.readline().split()))
ans = 10**18
for a,b,c in combinations(nums, 3):
    # lcm of three: lcm(lcm(a,b), c)
    l = a * b // math.gcd(a, b)
    l = l * c // math.gcd(l, c)
    if l < ans:
        ans = l
print(ans)