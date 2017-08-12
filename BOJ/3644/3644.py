import sys
dp=[[0 for col in range(2)] for row in range(10005)]
dp[0][0]=1
dp[1][0]=1
dp[1][1]=1
for i in range(2, 10005):
    dp[i][0]=dp[i-1][0]+dp[i-2][0]
    dp[i][1]=dp[i-1][1]+dp[i-2][1]
for line in sys.stdin:
    n=int(line)
    print(dp[n][0]+dp[n-1][1])

