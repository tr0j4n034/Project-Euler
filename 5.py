def gcd(a, b):
    while a > 0 and b > 0:
        if a >= b:
            a %= b
        else:
            b %= a
    return a + b

s = 1
for i in range(1, 21):
    s = s * i / gcd(s, i)
print(s)