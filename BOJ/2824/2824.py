def gcd (a, b):
    while b>0:
        temp=a
        a=b
        b=temp%b
    return a
n=int(input())
a=input().split(" ")
m=int(input())
b=input().split(" ")
p=1
q=1
for i in a :
    p*=int(i)
for i in b :
    q*=int(i)
ans=str(gcd(p, q))
if len(ans)>9 :
    print(ans[len(ans)-9:len(ans)])
else : 
    print(ans)

