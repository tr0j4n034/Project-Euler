import math


s = 0
for i in range(1, 101):
    r = int(math.sqrt(i))
    if r * r == i:
        continue
    N = i * (10**220)
    low, high, middle, best = 0, 10**114, 0, 0
    while low <= high:
        middle = (low + high + 1) // 2
        if middle * middle <= N:
            best = middle
            low = middle + 1
        else:
            high = middle - 1
    strbest = str(best)
    #assert(len(strbest) == 101)
    c = 0
    for j in range(0, 100):
        c += ord(strbest[j]) - 48
    s += c

print(s)
