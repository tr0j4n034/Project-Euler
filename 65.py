# again oeis:
# http://oeis.org/search?q=8%2C+11%2C+19%2C+87&sort=&language=english&go=Search

a = [0] * 305

a[0], a[1], a[2] = 1, 1, 2
for i in range(1, 100):
    a[3 * i] = a[3 * i - 1] + a[3 * i - 2]
    a[3 * i + 1] = 2 * i * a[3 * i] + a[3 * i - 1]
    a[3 * i + 2] = a[3 * i + 1] + a[3 * i]

for i in range(13):
    print(i, " --> ", a[i])

to = a[100 + 1]
s = 0
while to > 0:
    s += to % 10
    to //= 10
print(s)
