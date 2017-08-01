// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 07월 30일 23시 44분 34초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[40000];
int dp[55][40000];
int idx[40000];
pair<int, int> tree[160000];
map<int, int> mp;
void init(int x, int le, int ri, int node){
	if(le==ri){
		tree[node]={dp[x][le], 0};
		return;
	}
	int mid=(le+ri)/2;
	init(x, le, mid, node*2);
	init(x, mid+1, ri, node*2+1);
}
void update(int le, int ri, int val, int nodele, int noderi, int node){
	if(tree[node].second!=0){
		tree[node].first+=tree[node].second;
		if(nodele!=noderi){
			tree[node*2].second+=tree[node].second;
			tree[node*2+1].second+=tree[node].second;
		}
		tree[node].second=0;
	}
	if(ri<nodele||noderi<le)
		return;
	if(le<=nodele&&noderi<=ri){
		tree[node].first+=val;
		if(nodele!=noderi){
			tree[node*2].second+=val;
			tree[node*2+1].second+=val;
		}
		return;
	}
	int mid=(nodele+noderi)/2;
	update(le, ri, val, nodele, mid, node*2);
	update(le, ri, val, mid+1, noderi, node*2+1);
	tree[node].first=max(tree[node*2].first+tree[node*2].second, tree[node*2+1].first+tree[node*2+1].second);
}
int query(int le, int ri, int nodele, int noderi, int node){
	if(tree[node].second!=0){
		tree[node].first+=tree[node].second;
		if(nodele!=noderi){
			tree[node*2].second+=tree[node].second;
			tree[node*2+1].second+=tree[node].second;
		}
		tree[node].second=0;
	}
	if(ri<nodele||noderi<le)
		return 0;
	if(le<=nodele&&noderi<=ri)
		return tree[node].first;
	int mid=(nodele+noderi)/2;
	return max(query(le, ri, nodele, mid, node*2), query(le, ri, mid+1, noderi, node*2+1));
}
void solve(int x){
	memset(tree, 0, sizeof(tree));
	init(x-1, 0, n, 1);
	for(int i=1;i<=n;i++){
		update(idx[i], i-1, 1, 0, n, 1);
		dp[x][i]=max(dp[x-1][i], query(0, i-1, 0, n, 1));
	}
}
int main(){
	scanf("%d%d", &n, &k);
	for(int i=1;i<=n;i++){
		scanf("%d", &arr[i]);
		if(mp.count(arr[i]))
			idx[i]=mp[arr[i]];
		else
			idx[i]=0;
		mp[arr[i]]=i;
	}
	for(int i=1;i<=k;i++)
		solve(i);
	printf("%d\n", dp[k][n]);
	return 0;
}
