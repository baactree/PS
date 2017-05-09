// =====================================================================================
// 
//       Filename:  E.cpp
//        Created:  2017년 05월 08일 21시 46분 25초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> tree[300001];
vector<int> is[300001];
int ans=1;
int color[300001];
set<int> s;
void dfs(int now, int par){
	for(int i=0;i<is[now].size();i++)
		if(color[is[now][i]]!=-1)
			s.erase(color[is[now][i]]);
	for(int i=0;i<is[now].size();i++)
		if(color[is[now][i]]==-1){
			color[is[now][i]]=*s.begin();
			s.erase(s.begin());
		}
	for(int i=0;i<is[now].size();i++)
		s.insert(color[is[now][i]]);
	for(int i=0;i<tree[now].size();i++){
		int there=tree[now][i];
		if(there==par)
			continue;
		dfs(there, now);
	}
}
int main(){
	memset(color, -1, sizeof(color));
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++){
		int in;
		scanf("%d", &in);
		ans=max(ans, in);
		for(int j=0;j<in;j++){
			int c;
			scanf("%d", &c);
			is[i].push_back(c);
		}
	}
	for(int i=1;i<=ans;i++)
		s.insert(i);
	for(int i=0;i+1<n;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1, 0);
	printf("%d\n", ans);
	for(int i=1;i<=m;i++)
		printf("%d ", color[i]==-1?1:color[i]);
	printf("\n");
	return 0;
}

