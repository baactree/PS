from sys import stdin
tree = [0]*1005
def update(idx, val):
    idx+=1
    while idx < 1005:
        tree[idx]+=val
        idx+=idx&(-idx)
def query(idx):
    idx+=1
    ret=0
    while idx:
        ret+=tree[idx]
        idx-=idx&(-idx)
    return ret

input=stdin.readline
n, q=map(int, input().split())
for i in range(q):
    a, b, c=map(int, input().split())
    if a==1:
        update(b, c)
    else:
        print(query(c)-query(b-1))

