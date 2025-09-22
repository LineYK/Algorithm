import sys
input = sys.stdin.readline

def max_points(N, G, matches):
    base = 0
    draws = 0
    losses = []  

    for S, R in matches:
        if S > R:
            base += 3
        elif S == R:
            base += 1
            draws += 1
        else:
            losses.append(R - S)

    take = min(draws, G)
    base += 2 * take
    G -= take

    losses.sort()
    for d in losses:
        if G >= d + 1:
            G -= (d + 1)
            base += 3
        elif G == d:
            G -= d
            base += 1
            break
        else:
            break

    return base

def main():
    N, G = map(int, input().split())
    matches = [tuple(map(int, input().split())) for _ in range(N)]
    print(max_points(N, G, matches))

if __name__ == "__main__":
    main()
