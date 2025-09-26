import sys

a, b, c, d = map(int, sys.stdin.read().split())

def min_clock(a,b,c,d):
    s1 = int(f"{a}{b}{c}{d}")
    s2 = int(f"{b}{c}{d}{a}")
    s3 = int(f"{c}{d}{a}{b}")
    s4 = int(f"{d}{a}{b}{c}")
    return min(s1,s2,s3,s4)

target = min_clock(a,b,c,d)

vals = set()
for i in range(1,10):
    for j in range(1,10):
        for k in range(1,10):
            for l in range(1,10):
                vals.add(min_clock(i,j,k,l))

arr = sorted(vals)
# 1-based rank
print(arr.index(target) + 1)