import sys

def digit_sum(x):
    s = 0
    while x:
        s += x % 10
        x //= 10
    return s

def find_smallest_generator(N):
    L = len(str(N))
    start = max(1, N - 9 * L)
    for m in range(start, N):
        if m + digit_sum(m) == N:
            return m
    return 0

def main():
    N = int(sys.stdin.readline().strip())
    print(find_smallest_generator(N))

if __name__ == "__main__":
    main()
