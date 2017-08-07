// =====================================================================================
// 
//       Filename:  5012.cpp
//        Created:  2017년 08월 03일 03시 18분 58초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100000];
vector<int> tree[400000];
void init(int le, int ri, int node){
	if(le==ri){
		tree[node].push_back(arr[le]);
		return;
	}
	int mid=(le+ri)/2;
	init(le, mid, node*2);
	init(mid+1, ri, node*2+1);
	vector<int> now;
	for(int i=0;i<tree[node*2].size();i++)
		now.push_back(tree[node*2][i]);
	for(int i=0;i<tree[node*2+1].size();i++)
		now.push_back(tree[node*2+1][i]);
	sort(now.begin(), now.end());
	tree[node]=now;
}
int query(int le, int ri, int x, int mode, int nodele, int noderi, int node){
	if(le>noderi||ri<nodele)
		return 0;
	if(le<=nodele&&noderi<=ri){
		if(mode){
			int idx=upper_bound(tree[node].begin(), tree[node].end(), x)-tree[node].begin();
			return tree[node].size()-idx;
		}
		else
			return lower_bound(tree[node].begin(), tree[node].end(), x)-tree[node].begin();
	}
	int mid=(nodele+noderi)/2;
	return query(le, ri, x, mode, nodele, mid, node*2)
		+query(le, ri, x, mode, mid+1, noderi, node*2+1);
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	init(0, n-1, 1);
	long long ans=0;
	for(int i=1;i+1<n;i++){
		long long le=query(0, i-1, arr[i], 1, 0, n-1, 1);
		long long ri=query(i+1, n-1, arr[i], 0, 0, n-1, 1);
		ans+=le*ri;
	}
	printf("%lld\n", ans);
	return 0;
}

