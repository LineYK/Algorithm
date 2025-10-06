import sys
from collections import Counter, defaultdict
input = sys.stdin.readline

T = int(input().strip())
for _ in range(T):
    N = int(input().strip())
    teams = []
    for _i in range(N):
        line = input().split()
        team_name = line[0]
        school = line[1]
        solved = int(line[2])
        penalty = int(line[3])
        teams.append((team_name, school, solved, penalty))

    teams.sort(key=lambda x: (-x[2], x[3]))

    school_counts = Counter([sch for _, sch, _, _ in teams])
    school_cap = {sch: (cnt + 1) // 2 for sch, cnt in school_counts.items()}

    limit = min(60, N)  
    selected = [False] * N
    sel_count_by_school = defaultdict(int)
    selected_indices = []

    for i, (team_name, school, solved, penalty) in enumerate(teams):
        if len(selected_indices) >= limit:
            break
        pos = i + 1  
        cur = sel_count_by_school[school]
        cap = school_cap[school]
        if cur >= cap:
            continue

        allowed = False
        if 1 <= pos <= 10:
            if cur <= 3:
                allowed = True
        elif 11 <= pos <= 20:
            if cur <= 2:
                allowed = True
        elif 21 <= pos <= 30:
            if cur <= 1:
                allowed = True
        else:  
            if cur == 0:
                allowed = True

        if allowed:
            selected[i] = True
            selected_indices.append(i)
            sel_count_by_school[school] += 1

    if len(selected_indices) < limit:
        for i in range(N):
            if len(selected_indices) >= limit:
                break
            if not selected[i]:
                selected[i] = True
                selected_indices.append(i)

    worst_idx = max(selected_indices)  
    print(teams[worst_idx][0])
