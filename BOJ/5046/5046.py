from sys import stdin
input=stdin.readline
n, b, h, w=map(int, input().split())
ans=10**18
for i in range(h):
    p=int(input())
    arr=map(int, input().split())
    for j in arr:
        if j>=n and n*p <= b :
            ans=min(ans, n*p)
if ans==10**18:
    print("stay home")
else:
    print(ans)

