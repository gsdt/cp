import random

a = [1]

while len(a) < 100:
    if sum(a) + 1 <= 1000000000:
        a.append(sum(a) + 1)
    else:
        break


for i in range(70):
    a += [i + 1000000000 - 70]

print(len(a))
print(sum(a))
print(a)


