#include <bits/stdc++.h>
using namespace std;
int r[9];
int t[3][2]={
	{0,1},
	{0,2},
	{1,2}
};
int arr[19683];
int n;
const int inf=0x3f3f3f3f;
int solve(int idx,int state,int now){
	if(idx==9)
		return arr[state];
	int pick=(now/r[idx])%3;
	return solve(idx+1,state+t[pick][0]*r[idx],now)+
	solve(idx+1,state+t[pick][1]*r[idx],now);
}
int main(){
	r[0]=1;
	for(int i=1;i<9;i++)
		r[i]=r[i-1]*3;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int now=0;
		for(int j=0;j<9;j++){
			int x;
			scanf("%d",&x);
			now+=(x-1)*r[j];
		}
		arr[now]++;
	}
	int min_v,max_v;
	min_v=inf;
	max_v=0;
	for(int i=0;i<19683;i++){
		int now=solve(0,0,i);
		min_v=min(min_v,now);
		max_v=max(max_v,now);
	}
	printf("%d %d\n",min_v,max_v);
	return 0;
}