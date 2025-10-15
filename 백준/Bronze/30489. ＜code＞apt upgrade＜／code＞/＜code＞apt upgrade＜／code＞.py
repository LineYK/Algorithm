import sys
input = sys.stdin.readline

n, m, k = map(int, input().split())
sizes = list(map(int, input().split()))

total = sum(sizes)
sizes.sort(reverse=True)

q = min(n, m + k)
done_sum = sum(sizes[:q])

result = done_sum * 100.0 / total

print("{:.12f}".format(result).rstrip('0').rstrip('.') if abs(result - round(result)) > 1e-9 else str(int(round(result))))
