n = int(input())

if n % 2 == 0:
    n -= 1

tengah = (n - 1) / 2 

for x in range(n):
    for y in range(n):
        if x == y or x == (n - 1) - y:
            print("*", end = " ")
        else:
            print(" ", end = " ")
    print("")
