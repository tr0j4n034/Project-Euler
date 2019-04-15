best = 0
for i in range(2, 100):
    for j in range(2, 100):
        n = i ** j
        sum = 0
        while n > 0:
            sum += n % 10
            n //= 10
        if sum > best:
            best = sum
print best