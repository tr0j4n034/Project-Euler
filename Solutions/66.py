import math

def calculate(a):
    top, down = 1, a[-1]
    for i in range(len(a) - 2, -1, -1):
        #print(top, down)
        top = a[i] * down + top
        top, down = down, top
    return [down, top]

def getmatch(a, n, step):
    #print('now, step = ', step)
    if step == 0:
        for i in range(0, n):
            b = list(a)
            b.append(i)
            current = calculate(b)
            if current[0] ** 2 < current[1] ** 2 * n:
                return i - 1
            if current[0] ** 2 == current[1] ** 2 * n:
                return i - 1
        return n - 1
    else:
        for i in range(n - 1, 0, -1):
            b = list(a)
            b.append(i)
            current = calculate(b)
            if current[0] ** 2 < current[1] ** 2 * n:
                return i
            if current[0] ** 2 == current[1] ** 2 * n:
                return i
        return 0


high, num = 0, 0
for i in range(1, 1001):
    a = []
    a.append(int(math.sqrt(i)))
    if a[0] * a[0] == i:
        continue
    for j in range(0, 101):
        x = getmatch(a, i, j % 2)
        a.append(x)
        current = calculate(a)
        #print('appended', x)
        #print('now a = ', a)
        if current[0] ** 2 - i * (current[1] ** 2) == 1:
            break
#print(i, calculate(a))
current = calculate(a)
assert(current[0] != 0)
assert(current[0] ** 2 - i * (current[1] ** 2) == 1)
if current[0] > high:
    high, num = current[0], i

print(num, high)
