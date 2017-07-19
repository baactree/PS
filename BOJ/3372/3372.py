from sys import stdin
input=stdin.readline
n=int(input())
dp=[[0]*n for i in range(n)]
dp[0][0]=1
mat=[[int(i) for i in input().split()] for j in range(n)]
for i in range(n):
    for j in range(n):
        if mat[i][j]==0:
            continue
        if j+mat[i][j]<n:
            dp[i][j+mat[i][j]]+=dp[i][j]
        if i+mat[i][j]<n:
            dp[i+mat[i][j]][j]+=dp[i][j]
print(dp[n-1][n-1])
