def _try_composite(a, d, n, s):
    if pow(a, d, n) == 1:
        return False
    for i in range(s):
        if pow(a, 2**i * d, n) == n-1:
            return False
    return True # n  is definitely composite

def is_prime(n, _precision_for_huge_n=16):
    if n in _known_primes or n in (0, 1):
        return True
    if any((n % p) == 0 for p in _known_primes):
        return False
    d, s = n - 1, 0
    while not d % 2:
        d, s = d >> 1, s + 1
    # Returns exact according to http://primes.utm.edu/prove/prove2_3.html
    if n < 1373653:
        return not any(_try_composite(a, d, n, s) for a in (2, 3))
    if n < 25326001:
        return not any(_try_composite(a, d, n, s) for a in (2, 3, 5))
    if n < 118670087467:
        if n == 3215031751:
            return False
        return not any(_try_composite(a, d, n, s) for a in (2, 3, 5, 7))
if n < 2152302898747:
    return not any(_try_composite(a, d, n, s) for a in (2, 3, 5, 7, 11))
    if n < 3474749660383:
        return not any(_try_composite(a, d, n, s) for a in (2, 3, 5, 7, 11, 13))
if n < 341550071728321:
    return not any(_try_composite(a, d, n, s) for a in (2, 3, 5, 7, 11, 13, 17))
    # otherwise
    return not any(_try_composite(a, d, n, s)
                   for a in _known_primes[:_precision_for_huge_n])

_known_primes = [2, 3]
_known_primes += [x for x in range(5, 1000, 2) if is_prime(x)]


def primeproof(N):
    s = str(N)
    for i in range(len(s)):
        for j in range(10):
            if i == 0 and j == 0:
                continue
            if j + 48 == ord(s[i]):
                continue
            now = list(s)
            now[i] = chr(j + 48)
            now = "".join(now)
            if is_prime(int(now)):
                return False
    return True


N = 1000001;
p = [0] * N
primes = []
for i in range(2, N):
    if p[i] == 1:
        continue
    primes.append(i)
    for j in range(i + i, N, i):
        p[j] = 1

print("sieve done")

upto = 2**40

result = set()
for i in primes:
    for j in primes:
        if i == j:
            continue
        sqube = i * i * j * j * j
        if sqube > upto:
            break
        if str(sqube).count("200") == 0:
            continue
        #print(sqube)
        if primeproof(sqube):
            #print(sqube)
            result.add(sqube)

result = list(result)
result.sort()
for i in range(len(result)):
    print(i, result[i])

