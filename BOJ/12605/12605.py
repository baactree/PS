import sys
n=int(input())
for i in range(0,n):
	arr=list(map(str,input().split(' ')))
	#print("Case #%d:" % int(i+1) , end="")
	sys.stdout.write("Case #%d:" % int(i+1))
	arr.reverse()
	for x in arr:
	#	print(" %s" % x , end="")
		sys.stdout.write(" %s" % x)
	print()
