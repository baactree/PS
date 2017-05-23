from sys import stdin
input = stdin.readline
n=int(input())
arr=[0, 0, 0]
for i in range(n):
    s=map(int, input().split('/'))
    idx=0
    if s[0]==3 :
        idx=2
    elif s[1]==4:
        idx=1
    else :
        idx=0
    arr[idx]+=1
ans=arr[2]
arr[1]=max(0, arr[1]-arr[2])
ans+=(arr[0]+1)//2
if arr[0]%2!=0 :
    arr[1]=max(0, arr[1]-2)
ans+=(arr[1]+3)//4
print(ans)

    

