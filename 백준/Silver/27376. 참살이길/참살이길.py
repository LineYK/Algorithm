import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    lights = []
    for _ in range(k):
        x, t, s = map(int, input().split())
        lights.append((x, t, s))
    lights.sort()

    cur_pos = 0
    cur_time = 0

    for x, t, s in lights:
        arr = cur_time + (x - cur_pos)

        if arr < s:
            wait = s - arr
        else:
            d = arr - s
            period = 2 * t
            r = d % period
            if r < t:
                wait = 0
            else:
                wait = period - r

        cur_time = arr + wait
        cur_pos = x

    cur_time += (n - cur_pos)
    print(cur_time)

if __name__ == "__main__":
    main()
