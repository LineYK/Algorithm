import sys
input = sys.stdin.readline

n = int(input().strip())
p_tokens = input().split()   
q_tokens = input().split()   

if n == 1:
    print("good puzzle" if p_tokens[0] == q_tokens[0] else "bad puzzle")
    sys.exit(0)

sep = '#'
p_str = sep.join(p_tokens)
q_str = sep.join(q_tokens)

if q_str in p_str + sep + p_str:
    print("good puzzle")
    sys.exit(0)

rp_str = sep.join(reversed(p_tokens))
if q_str in rp_str + sep + rp_str:
    print("good puzzle")
else:
    print("bad puzzle")
