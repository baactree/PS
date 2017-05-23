n, l=map(int, raw_input().split())
ans = 0
while n > 0 :
    ans+=1
    s=str(ans)
    if s.find(str(l))==-1:
        n-=1
    
print(ans)
    
