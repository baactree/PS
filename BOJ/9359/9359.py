from sys import stdin
input=stdin.readline
def solve(idx, r, x, k, n, div):
    if k==n:
        if n%2==1:
            return -(x//r)
        return x//r
    if(idx==len(div)):
        return 0
    ret=0
    ret+=solve(idx+1, r, x, k, n, div)
    ret+=solve(idx+1, r*div[idx], x, k+1, n, div)
    return ret

def f(x, div):
    ret=x
    for i in range(len(div)):
        ret+=solve(0, 1, x, 0, i+1, div)
    return ret
p=[0]*100005
prime=[]
for i in range(2, 100005):
    if(p[i]==0):
        prime.append(i)
        for j in range(i+i, 100005, i):
            p[j]=1

testcase=int(input())
for tc in range(testcase):
    a, b, n=map(int, input().split())
    div=[]
    for i in prime:
        if n==1:
            break
        if(n%i==0):
            div.append(i)
        while(n%i==0):
            n/=i
    if n>1:
        div.append(n)
    print("Case #%d: %d"%(tc+1, f(b, div)-f(a-1, div)))

