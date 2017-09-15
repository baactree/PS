// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 09월 14일 19시 40분 20초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[5005];
int arr[5005];
int cache[5005];
int dfs(int now){
	int &ret=cache[now];
	if(ret!=-1)
		return ret;
	ret=1;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		ret=max(ret, dfs(there)+1);
	}
	return ret;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++)
		scanf("%d", &arr[i]);
	for(int i=0;i<m;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		if(arr[a]>arr[b])
			swap(a, b);
		adj[a].push_back(b);
	}
	memset(cache, -1, sizeof(cache));
	for(int i=1;i<=n;i++){
		printf("%d\n", dfs(i));
	}
	return 0;
}

