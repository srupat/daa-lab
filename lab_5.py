def fma(a, b, n):
    if b == 1:
        return a % n
    
    half = fma(a, b // 2, n)
    
    if b % 2 == 0:
        return (half * half) % n
    
    else:
        return (half * half * (a % n)) % n
    
print(fma(7, 13, 15))