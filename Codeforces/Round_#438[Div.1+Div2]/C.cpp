#include <bits/stdc++.h>
using namespace std;
int n,k;
int arr[100005];
int cache[100005][1<<4];
int solve(int idx,int state){
	if(idx==n)
		return state==0;
	int &ret=cache[idx][state];
	if(ret!=-1)
		return ret;
	ret=solve(idx+1,state);
	if((arr[idx]&state)==0)
		ret=true;
	return ret;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			int x;
			scanf("%d",&x);
			arr[i]=arr[i]*2+x;
		}
	}
	bool ans=0;
	memset(cache,-1,sizeof(cache));
	for(int i=0;i<n;i++)
		ans|=solve(i+1,arr[i]);
	printf("%s\n",ans?"YES":"NO");
	return 0;
}