n = int(input())

if n % 2 == 0:
    n -= 1

print((n + 1) / 2)

for a in range(5):
    print(a, end = " ")
print()

for x in range(n):                          #Horizontal
    if x == 0 or x == n - 1:
        for y in range(n):
            print("*", end = " ")
    if x == (n + 1) / 2:
        for y in range(n):
            if y == 0 or y == n - 1:
                print("*", end = " ")
            else:
                print(" ", end = " ")
    print()
