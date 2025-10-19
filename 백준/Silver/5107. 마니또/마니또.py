import sys

case_no = 1
for line in sys.stdin:
    line = line.strip()
    if not line:
        continue
    N = int(line)
    if N == 0:
        break

    name_to_idx = {}
    to = [-1] * N
    idx = 0

    pairs = []
    for _ in range(N):
        a, b = sys.stdin.readline().split()
        pairs.append((a, b))
        if a not in name_to_idx:
            name_to_idx[a] = idx
            idx += 1
        if b not in name_to_idx:
            name_to_idx[b] = idx
            idx += 1

    for a, b in pairs:
        ai = name_to_idx[a]
        bi = name_to_idx[b]
        to[ai] = bi

    visited = [False] * N
    cycles = 0

    for i in range(N):
        if not visited[i]:
            cur = i
            while not visited[cur]:
                visited[cur] = True
                cur = to[cur]

    visited = [False] * N
    cycles = 0
    for i in range(N):
        if not visited[i]:
            cur = i
            path_set = set()
            while True:
                if cur in path_set:
                    cycles += 1
                    break
                if visited[cur]:
                    break
                path_set.add(cur)
                cur = to[cur]
            for v in path_set:
                visited[v] = True

    print(f"{case_no} {cycles}")
    case_no += 1
