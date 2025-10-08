import sys
input = sys.stdin.readline

n = int(input().strip())
p = int(input().strip())
arr = list(map(int, input().split()))

ans = 0
if p % 2 == 0:
    for a in arr:
        ans += a*a
else:
    if p == 1:
        for a in arr:
            if a > 0:
                ans += a
    else:  
        for a in arr:
            if a > 0:
                ans += a*a*a

print(ans)
