s = 0
for i in range(100, 1000):
    for j in range(100, 1000):
        x = i * j
        if str(x) == str(x)[::-1] and x > s:
            s = x
print(s)