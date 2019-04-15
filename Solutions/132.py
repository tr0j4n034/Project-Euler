def mod_power(a, b, modulo):
    if b == 0:
        return 1 % modulo
    if b % 2 == 1:
        return a * mod_power(a, b - 1, modulo) % modulo
    else:
        return mod_power(a * a % modulo, b / 2, modulo)


def calculate_modulo(length, modulo):
    if length == 1:
        return 1 % modulo
    if length % 2 == 1:
        return (calculate_modulo(length - 1, modulo) * 10 + 1) % modulo
    else:
        half = calculate_modulo(length / 2, modulo)
        multiplier = mod_power(10, length / 2, modulo)
        return (half * multiplier + half) % modulo


def is_prime(N):
    if N < 2:
        return False
    for i in range(2, N):
        if i * i > N:
            break
        if N % i == 0:
            return False
    return True


N = 10**9
factors = []
for i in range(2, 250000):
    if not is_prime(i):
        continue
    now, steps = i, 0
    while calculate_modulo(N, now) == 0:
        steps += 1
        factors.append(i)
        now *= i
    if steps > 0:
        print(i, steps)
    if len(factors) >= 40:
        break

print(len(factors))
print(factors)

print(sum(factors))
