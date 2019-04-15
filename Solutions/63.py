result = 0
for i in range(1, 10):
    for j in range(120):
        p = i ** j
        if j == len(str(p)):
            print(i, j)
            result += 1
print(result)
