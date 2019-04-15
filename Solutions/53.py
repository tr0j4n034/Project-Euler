c = [[0 for i in range(101)] for j in range(101)]

for i in range(101):
    for j in range(i + 1):
        if i == 0 or j == 0:
            c[i][j] = 1
        else:
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j]

result = 0
for i in range(101):
    for j in range(101):
        if c[i][j] > 1000000:
            result += 1
print result
