import random

N_CASE = 100
N = 10
MAX = 1000000000

def gen_pos(N):
    # next = [str(i) for i in range(N)]
    # if 0 in next:
    #     return next
    # # next[0] = str(0)
    # return next
    return "0 1 1 2 2 3 3 4 4 5".split(' ')

with open('input.txt', 'w') as f:
    f.write(f"{N_CASE}\n")
    for i in range(N_CASE):
        f.write(f"{N}\n")
        val = [str(random.randint(1, 10)) for i in range(N)]
        next = gen_pos(N)
        f.write(f"{' '.join(val)}\n")
        f.write(f"{' '.join(next)}\n")


