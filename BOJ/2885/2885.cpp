#include <bits/stdc++.h>
using namespace std;
int solve(int r,int k){
	if(r==k)
		return 0;
	r/=2;
	if(r<k)
		return solve(r,k-r)+1;
	return solve(r,k)+1;
}
int main(){
	int k;
	scanf("%d",&k);
	int r=1;
	while(r<k)
		r<<=1;
	printf("%d ",r);
	printf("%d\n",solve(r,k));
	return 0;
}