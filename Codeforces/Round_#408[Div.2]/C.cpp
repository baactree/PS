// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 04월 25일 22시 42분 50초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> adj[300005];
int arr[300005];
int tree[1200005];
int update(int idx, int val, int nodele, int noderi, int node){
	if(idx<nodele||noderi<idx)
		return tree[node];
	if(nodele==noderi)
		return tree[node]=val;
	int mid=(nodele+noderi)/2;
	return tree[node]=max(update(idx, val, nodele, mid, node*2), update(idx, val, mid+1, noderi, node*2+1));
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<1200005;i++)
		tree[i]=-0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		scanf("%d", &arr[i]);
		update(i, arr[i]+2, 1, n, 1);
	}
	for(int i=0;i<n-1;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		update(i, arr[i], 1, n, 1);
		for(int j=0;j<adj[i].size();j++){
			int there=adj[i][j];
			update(there, arr[there]+1, 1, n, 1);
		}
		ans=min(ans, tree[1]);
		update(i, arr[i]+2, 1, n, 1);
		for(int j=0;j<adj[i].size();j++){
			int there=adj[i][j];
			update(there, arr[there]+2, 1, n, 1);
		}
	}
	printf("%d\n", ans);
	return 0;
}

