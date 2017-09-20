// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 09월 19일 22시 57분 41초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[200005];
vector<vector<int> > ans;
int trip[200005];
vector<int> dfs(int now, int par){
	trip[now]=1;
	vector<int> ret;
	if(par)
		ret.push_back(par);
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(there==par)
			continue;
		if(trip[there]==1){
			ret.push_back(there);
		}
		else if(!trip[there]){
			vector<int> temp=dfs(there, now);
			for(int j=0;j<temp.size();j++)
				ret.push_back(temp[j]);
		}
	}
	while(ret.size()>1){
		int a=ret.back();
		ret.pop_back();
		int b=ret.back();
		ret.pop_back();
		ans.push_back(vector<int>({a, now, b}));
	}
	trip[now]=2;
	if(ret.size()==1)
		ret[0]=now;
	return ret;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=1;i<=n;i++)
		if(!trip[i])
			dfs(i, 0);
	printf("%d\n", ans.size());
	for(int i=0;i<ans.size();i++)
		for(int j=0;j<ans[i].size();j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}
	return 0;
}

