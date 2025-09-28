import sys
import heapq

def main():
    input = sys.stdin.readline
    n = int(input().strip())
    arr = list(map(int, input().split()))
    if n == 1:
        print("{:.12f}".format(float(arr[0])))
        return

    heap = [float(x) for x in arr]
    heapq.heapify(heap)

    while len(heap) > 1:
        a = heapq.heappop(heap)
        b = heapq.heappop(heap)
        heapq.heappush(heap, (a + b) / 2.0)

    ans = heap[0]
    print("{:.12f}".format(ans))

if __name__ == "__main__":
    main()
