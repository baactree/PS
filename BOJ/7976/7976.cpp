#include <bits/stdc++.h>
using namespace std;
int n,k;
int arr[1000005][2];
int cache[1000005][2];
const int inf=0x3f3f3f3f;
int solve(int idx,int state){
	if(idx==k)
		return state==0?0:inf;
	int &ret=cache[idx][state];
	if(ret!=-1)
		return ret;
	ret=solve(idx+1,state)+arr[idx][1];
	ret=min(ret,solve(idx+1,(state+1)&1)+arr[idx][0]);
	return ret;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		arr[i%k][x&1]++;
	}
	memset(cache,-1,sizeof(cache));
	printf("%d\n",solve(0,0));
	return 0;
}