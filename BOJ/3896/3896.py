from sys import stdin
import bisect
input=stdin.readline

def upper_bound(st, fi, val, arr):
    le=st
    ri=fi-1
    ret=fi
    while le<=ri:
        mid=(le+ri)//2
        if arr[mid]>val:
            ret=mid
            ri=mid-1
        else:
            le=mid+1
    return ret
p=[0]*1500000
prime=[]
for i in range(2, 1500000):
    if p[i]==0:
        prime.append(i)
        for j in range(i+i, 1500000, i):
            p[j]=1
testcase=int(input())
for _ in range(testcase):
    k=int(input())
    if p[k]==0:
        print(0)
        continue
    idx=bisect.bisect(prime, k)
    print(prime[idx]-prime[idx-1])

