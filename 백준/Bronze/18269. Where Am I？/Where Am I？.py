import sys
input = sys.stdin.readline

N = int(input().strip())
s = input().strip()

for K in range(1, N+1):
    seen = set()
    ok = True
    for i in range(0, N - K + 1):
        sub = s[i:i+K]
        if sub in seen:
            ok = False
            break
        seen.add(sub)
    if ok:
        print(K)
        break
