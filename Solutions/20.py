import math

n, sum = math.factorial(100), 0
while n > 0:
    sum += n % 10
    n //= 10
print(sum)