#include <bits/stdc++.h>
using namespace std;
int n,m,k;
char trans[300];
int arr[1005];
int cache[505][1005];
vector<pair<int,int> > adj[505];
int solve(int now,int idx){
	if(idx==n)
		return 0;
	int &ret=cache[now][idx];
	if(ret!=-1)
		return ret;
	ret=0;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i].first;
		int type=adj[now][i].second;
		int cost=(type==arr[idx]?10:0);
		ret=max(ret,solve(there,idx+1)+cost);
	}
	return ret;
}
int main(){
	trans['R']=0;
	trans['G']=1;
	trans['B']=2;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		char in[2];
		scanf("%s",in);
		arr[i]=trans[in[0]];
	}
	scanf("%d%d",&m,&k);
	for(int i=0;i<k;i++){
		int a,b;
		char in[2];
		scanf("%d%d%s",&a,&b,in);
		adj[a].push_back({b,trans[in[0]]});
		adj[b].push_back({a,trans[in[0]]});
	}
	memset(cache,-1,sizeof(cache));
	printf("%d\n",solve(1,0));
	return 0;
}