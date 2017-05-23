from sys import stdin
input=stdin.readline
def solve(k1, k2, turn, b1, b2, b3, cache):
    if(k1 < 0 or k2 < 0):
        return 1-turn
    if(cache[k1][k2][turn]!=-1):
        return cache[k1][k2][turn]
    if(turn == 1):
        ret=1
        ret=min(ret, solve(k1-b1, k2, 1-turn, b1, b2, b3, cache))
        ret=min(ret, solve(k1-b2, k2, 1-turn, b1, b2, b3, cache))
        ret=min(ret, solve(k1-b3, k2, 1-turn, b1, b2, b3, cache))
        ret=min(ret, solve(k1, k2-b1, 1-turn, b1, b2, b3, cache))
        ret=min(ret, solve(k1, k2-b2, 1-turn, b1, b2, b3, cache))
        ret=min(ret, solve(k1, k2-b3, 1-turn, b1, b2, b3, cache))
        cache[k1][k2][turn]=ret
        return ret
    ret=0
    ret=max(ret, solve(k1-b1, k2, 1-turn, b1, b2, b3, cache))
    ret=max(ret, solve(k1-b2, k2, 1-turn, b1, b2, b3, cache))
    ret=max(ret, solve(k1-b3, k2, 1-turn, b1, b2, b3, cache))
    ret=max(ret, solve(k1, k2-b1, 1-turn, b1, b2, b3, cache))
    ret=max(ret, solve(k1, k2-b2, 1-turn, b1, b2, b3, cache))
    ret=max(ret, solve(k1, k2-b3, 1-turn, b1, b2, b3, cache))
    cache[k1][k2][turn]=ret
    return ret

b1, b2, b3=map(int, input().split())
cache=[[[-1]*2 for i in range(505)] for j in range(505)]
for _ in range(5):
    k1, k2=map(int, input().split())
    ans=solve(k1, k2, 0, b1, b2, b3, cache)
    if(ans==1):
        print("A")
    else:
        print("B")

