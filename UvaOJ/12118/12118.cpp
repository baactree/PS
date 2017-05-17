// =====================================================================================
// 
//       Filename:  12118.cpp
//        Created:  2017년 05월 15일 18시 50분 13초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int v, e, t;
vector<vector<int> > adj;
vector<bool> trip;
int dfs(int now){
	if(trip[now])
		return 0;
	trip[now]=true;
	int ret=adj[now].size()&1;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		ret+=dfs(there);
	}
	return ret;
}
int main(){
	int testcase=1;
	while(scanf("%d%d%d", &v, &e, &t)){
		if(v==0&&e==0&&t==0)
			break;
		adj.clear();
		adj.resize(v+1);
		trip=vector<bool>(v+1, 0);
		for(int i=0;i<e;i++){
			int a, b;
			scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int comp=0;
		int cnt=e;
		for(int i=1;i<=v;i++){
			if(!trip[i]&&adj[i].size()>0){
				int now=dfs(i);
				comp++;
				cnt+=max(0, now/2-1);
			}
		}
		printf("Case %d: %d\n",testcase++, t*(cnt+max(0, comp-1)));
	}
	return 0;
}

