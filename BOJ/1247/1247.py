from sys import stdin
input = stdin.readline
for i in range (0, 3):
    s = 0;
    n = int(input())
    for j in range (0, n):
        k = int(input())
        s = s+k
    if s > 0:
        print("+")
    elif s < 0:
        print("-")
    else :
        print("0")
