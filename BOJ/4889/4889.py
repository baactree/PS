#from sys import stdin
#input = stdin.readline
tc=1
while True:
	arr=str(input())
	if arr.count('-') > 0 :
		break
	n = len(arr)
	dp = [[1e9]*(n+1) for i in range(n+1)]
	dp[0][0]=0
	for i in range(0,n):
		for j in range(0,n):
			if arr[i]=='{':
				dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j])
				if j>0:
					dp[i+1][j-1]=min(dp[i+1][j-1],dp[i][j]+1)
			else:
				dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+1)
				if j>0:
					dp[i+1][j-1]=min(dp[i+1][j-1],dp[i][j])
	print("%d. %d" % (tc,dp[n][0]))
	tc+=1
