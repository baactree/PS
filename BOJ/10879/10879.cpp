#include <bits/stdc++.h>
using namespace std;
int cache[50005];
int chk[1<<17];
int solve(int x){
	if(chk[x])
		return chk[x];
	int &ret=cache[x];
	if(ret!=-1)
		return ret;
	ret=0x3f3f3f3f;
	int r=1;
	while(r<x){
		ret=min(ret,solve(x-r)+solve(r)+4);
		r*=2;
	}
	ret=min(ret,solve(abs(x-r))+solve(r)+4);
	return ret;
}
int main(){
	int r=1;
	int cnt=1;
	while(r<(1<<17)){
		chk[r]=cnt;
		r*=2;
		cnt++;		
	}
	int testcase;
	scanf("%d",&testcase);
	memset(cache,-1,sizeof(cache));
	while(testcase--){
		int n;
		scanf("%d",&n);
		printf("%d\n",solve(abs(n)));
	}	
	return 0;
}