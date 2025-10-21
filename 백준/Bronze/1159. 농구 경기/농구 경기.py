import sys
input = sys.stdin.readline

N = int(input().strip())
cnt = {}
for _ in range(N):
    name = input().strip()
    if not name: 
        continue
    ch = name[0]
    cnt[ch] = cnt.get(ch, 0) + 1

res = []
for c in sorted(cnt.keys()):
    if cnt[c] >= 5:
        res.append(c)

if res:
    print(''.join(res))
else:
    print("PREDAJA")
