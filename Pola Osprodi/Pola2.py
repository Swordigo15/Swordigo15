n = int(input())

if n % 2 == 0:
    n -= 1

tengah = (n - 1) / 2

for x in range(n):
    for y in range(n):
        if x == tengah or y == tengah or x == 0 or x == n - 1 or y == 0 or y == n - 1:
            print("*", end = " ")
        else:
            print(" ", end = " ")
    print("")