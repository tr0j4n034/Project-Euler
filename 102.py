def area(x1, y1, x2, y2, x3, y3):
    return abs(x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3)


result = 0
while True:
    line = input()
    if line == "":
        break
    coords = list(map(int, line.split(',')))
    #print(coords)
    total = area(coords[0], coords[1], coords[2], coords[3], coords[4], coords[5])
    s1 = area(coords[0], coords[1], coords[2], coords[3], 0, 0)
    s2 = area(coords[0], coords[1], coords[4], coords[5], 0, 0)
    s3 = area(coords[2], coords[3], coords[4], coords[5], 0, 0)
    if s1 + s2 + s3 == total:
        result += 1
print(result)
