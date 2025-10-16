import sys
input = sys.stdin.readline

T = int(input().strip())
for _ in range(T):
    s, t = input().split()
    a = 0  
    b = 0  
    for ch1, ch2 in zip(s, t):
        if ch1 == '1' and ch2 == '0':
            a += 1
        elif ch1 == '0' and ch2 == '1':
            b += 1
    print(max(a, b))
