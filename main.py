data = {}
for i in range(38745938745897, 387459387458978):
    sq = i * i
    s = ''.join(sorted(str(sq)))
    if s not in data:
        data[s] = []
    data[s].append(sq)



for e in data:
    if len(data[e]) == len(e):
        print(data[e])
