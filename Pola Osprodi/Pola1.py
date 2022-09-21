n = int(input())

if n % 2 == 0:
    n -= 1

tengah = (n - 1) / 2

for x in range(n):
    o = abs(x - tengah)
    for y in range(n):
        p = abs(y - tengah)
        if y >= tengah - o and y <= tengah + o:
            if y % 2 == 0:
                if x % 2 == 0:
                    print("*", end = " ")
                else:
                    print(" ", end = " ")
            else:
                if x % 2 != 0:
                    print("*", end = " ")
                else:
                    print(" ", end = " ")
        else:
            print(" ", end =" ")
    print("")