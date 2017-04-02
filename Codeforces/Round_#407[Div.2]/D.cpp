// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 04월 02일 15시 58분 01초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[1000001];
bool trip[1000001];
typedef long long ll;
ll solve(int x){
	trip[x]=true;
	ll ret=0;
	ll cnt=0;
	for(int i=0;i<adj[x].size();i++){
		int there=adj[x][i];
		if(there!=x)
			cnt++;
		if(!trip[there])
			ret+=solve(there);
	}
	ret+=cnt*(cnt-1)/2;
	return ret;
}
int dfs(int x){
	trip[x]=true;
	int ret=adj[x].size();
	for(int i=0;i<adj[x].size();i++){
		int there=adj[x][i];
		if(!trip[there])
			ret+=dfs(there);
	}
	return ret;
}
int main(){
	scanf("%d%d", &n, &m);
	ll cnt=0;
	for(int i=0;i<m;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		if(a==b)
			cnt++;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int st;
	for(int i=1;i<=n;i++){
		if(adj[i].size()==0)
			continue;
		if(dfs(i)!=m*2){
			printf("0\n");
			return 0;
		}
		else{
			st=i;
			break;
		}
	}
	memset(trip, 0, sizeof(trip));
	printf("%lld\n", solve(st)+cnt*(m-cnt)+cnt*(cnt-1)/2);
	return 0;
}

