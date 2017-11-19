from sys import stdin
input = stdin.readline
inf=1e9+5
ansmin = inf
ansmax = -inf
n = int(input())
arr=list(map(int,input().split()))
cnt=list(map(int,input().split()))
pick=[0]*(n-1)
def calc():
	ans = arr[0]
	for i in range (0,n-1):
		if pick[i]==0:
			ans=ans+arr[i+1]
		elif pick[i]==1:
			ans=ans-arr[i+1]
		elif pick[i]==2:
			ans=ans*arr[i+1]
		elif pick[i]==3:
			if ans < 0 and arr[i+1]>0:
				ans*=-1
				ans=ans//arr[i+1]
				ans*=-1
			else:
				ans=ans//arr[i+1]
	return ans
def solve(idx):
	if idx == n-1:
		now=calc()
		global ansmin
		global ansmax
		ansmin=min(ansmin,now)
		ansmax=max(ansmax,now)
	for i in range(0,4):
		if cnt[i] > 0:
			cnt[i]-=1
			pick[idx]=i
			solve(idx+1)
			cnt[i]+=1
solve(0)
print(ansmax)
print(ansmin)