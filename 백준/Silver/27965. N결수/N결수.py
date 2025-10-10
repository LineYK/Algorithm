N, K = map(int, input().split())

rem = 0
power10 = 1

for i in range(1, N + 1):
    d = len(str(i))
    power10 = pow(10, d, K)
    rem = (rem * power10 + i) % K

print(rem)
