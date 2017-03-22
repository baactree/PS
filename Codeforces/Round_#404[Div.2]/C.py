def possi(x, n, m):
    if x<=m:
        return n-x<=0
    x-=m
    return (n-m)<=x*(x+1)/2
n, m=raw_input().split(" ")
n=int(n)
m=int(m)
if n<=m:
    print(n)
else:
    le = int(1)
    ri = int(n)
    mid = 0
    ans = 0
    while le<=ri:
        mid = (le+ri)/2
        if possi(mid, n, m) :
            ans=mid
            ri=mid-1
        else:
            le=mid+1
    print(ans)
