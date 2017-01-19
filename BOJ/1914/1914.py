def solve(n, s, d, t):
    if n==0 :
        return
    solve(n-1, s, t, d)
    print("%d %d" % (s, d))
    solve(n-1, t, d, s)
n = int(input())
print(pow(2, n)-1)
if n <= 20 :
    solve(n, 1, 3, 2)
