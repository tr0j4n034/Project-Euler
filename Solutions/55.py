def good(N):
    s = str(N)
    if s == s[::-1]:
        return True
    else:
        return False
    
def check(N):
    for i in range(50):
        N = N + int(str(N)[::-1])
        if good(N) == True:
            #print(i, N)
            return True
    return False

count = 0
for i in range(10000):
    if check(i) == False:
        count += 1
print count