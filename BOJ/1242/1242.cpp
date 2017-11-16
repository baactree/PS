#include <bits/stdc++.h>
using namespace std;
int solve(int n,int m,int k){
	int t=(m-1)%n+1;
	if(k==t)
		return 1;
	if(t<k)
		return solve(n-1,m,k-t)+1;
	return solve(n-1,m,k+n-t)+1;
}
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	printf("%d\n",solve(n,m,k));
	return 0;
}