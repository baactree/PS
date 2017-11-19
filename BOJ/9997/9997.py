n=int(input())
arr = [0]*n
for i in range(0,n):
	x=str(input())
	for s in x:
		idx=int(ord(s))-97
		arr[i]|=1<<idx
def solve(idx,state):
	global n
	if idx==n:
		if state==((1<<26)-1):
			return 1
		return 0
	ret=0
	ret+=solve(idx+1,state)
	ret+=solve(idx+1,state|arr[idx])
	return ret
print(solve(0,0))
