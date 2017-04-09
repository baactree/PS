while 1>0:
    n, k=input().split(' ')
    n=int(n)
    k=int(k)
    if n==0 and k==0 :
        break
    if k>n-k:
        k=n-k
    ans = 1
    for i in range(n-k+1, n+1):
        ans*=i
    for i in range(1, k+1):
        ans/=i
    print(int(ans))


