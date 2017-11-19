from sys import stdin
input=stdin.readline
n,k,a=map(int,input().split())
t=[0]*n
s=[0]*n
for i in range(0,n):
	t[i],s[i]=map(int,input().split())
ans=1e9
for i in range(0,n):
	r=k//a
	p=(r+t[i]-1)//t[i]-1
	ans=min(ans,p*(t[i]+s[i])+r-p*t[i])
print(ans)

