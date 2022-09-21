n = int(input())

if n % 2 == 0:
    n -= 1

tengah = (n - 1) / 2

for x in range(n): 
    o = abs(x - tengah)
    for y in range(n):
        if y > o and y < (2 * tengah) - o:
            print(" ", end = " ")
        else:
            print("*", end = " ")
    print()
