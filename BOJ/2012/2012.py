from sys import stdin
input = stdin.readline
n = int(input())
arr = [0]*n
for i in range(n):
    arr[i]=int(input())
arr.sort()
ans = 0
for i in range(n):
    ans += abs(i+1-arr[i])
print(ans)
