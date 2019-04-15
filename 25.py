fib = [0] * 9000
fib[1] = 1
for i in range(2, 9000):
    fib[i] = fib[i - 1] + fib[i - 2]
    if len(str(fib[i])) >= 1000:
        print(i)
        print('exiting')
        exit(0)
print('done')