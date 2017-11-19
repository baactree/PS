mat = []
for i in range(0,4):
	x=str(input())
	mat.append(x)
k = int(input())
for _ in range(k):
	a,b=map(int,input().split())
	a-=1
	check = [0]*4
	check[a]=b
	for i in range(a,3):
		if mat[i][2]!=mat[i+1][6]:
			check[i+1]=check[i]*(-1)
		else:
			break
	for i in range(a,0,-1):
		if mat[i][6]!=mat[i-1][2]:
			check[i-1]=check[i]*(-1)
		else:
			break
	for i in range(4):
		if check[i]==1:
			mat[i]=mat[i][7]+mat[i][:7]
		elif check[i]==-1:
			mat[i]=mat[i][1:]+mat[i][0]
ans=0
for i in range(4):
	ans+= int(mat[i][0])*pow(2,i)
print(ans)
