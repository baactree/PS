from sys import stdin
import math
input=stdin.readline
a, b=map(int, input().split())
c=math.sqrt(a*b)
print("%.6lf %.6lf"%(c, c))
