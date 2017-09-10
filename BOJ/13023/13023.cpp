// =====================================================================================
// 
//       Filename:  13023.cpp
//        Created:  2017년 09월 10일 18시 39분 37초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[2005];
bool chk[2005];
bool dfs(int now, int d){
	if(d==5)
		return true;
	chk[now]=true;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(chk[there])
			continue;
		if(dfs(there, d+1)){
			chk[now]=false;
			return true;
		}
	}
	chk[now]=false;
	return false;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=0;i<n;i++){
		if(dfs(i, 1))
			return !printf("1\n");
	}
	return !printf("0\n");
}

