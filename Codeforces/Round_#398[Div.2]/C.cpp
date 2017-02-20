// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 02월 20일 21시 44분 07초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> adj[1000001];
int root;
int sum[1000001];
int t[1000001];
vector<int> ans;
int s;
void dfs(int v){
	sum[v]=t[v];
	for(int i=0;i<adj[v].size();i++){
		int there=adj[v][i];
		dfs(there);
		sum[v]+=sum[there];
	}
	if(sum[v]==s/3&&v!=root){
		ans.push_back(v);
		sum[v]=0;
	}
}
int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		if(a==0)
			root=i;
		adj[a].push_back(i);
		t[i]=b;
		s+=b;
	}
	if(s%3!=0){
		printf("-1\n");
		return 0;
	}
	dfs(root);
	if(ans.size()<2)
		printf("-1\n");
	else
		printf("%d %d\n", ans[0], ans[1]);
	return 0;
}

