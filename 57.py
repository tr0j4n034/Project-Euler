a, b = 1, 1
count = 0
for i in range(1000):
    a, b = a + b + b, a + b
    if len(str(a)) > len(str(b)):
        count += 1
print count