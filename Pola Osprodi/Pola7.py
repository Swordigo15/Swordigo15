n = int(input())

if n % 2 == 0:
    n -= 1

tengah = int((n - 1) / 2)

for x in range(n):
    for y in range(n):
        p = abs(y - tengah)
        if x >= tengah - p and x <= tengah + p:
            print("*", end =" ")
        else:
            print(" ", end =" ")
    print("")