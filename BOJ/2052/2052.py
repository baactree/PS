n=int(input())
k=str(5**n)
print("0.", end='')
a=n-len(k)
for i in range(a):
    print("0", end='')
print(k)
