// =====================================================================================
// 
//       Filename:  7469.cpp
//        Created:  2017년 04월 02일 13시 16분 26초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
vector<int> tree[400000];
int n, m;
vector<int> arr;
void init(int le, int ri, int node){
	if(le==ri){
		tree[node].push_back(arr[le]);
		return;
	}
	int mid=(le+ri)/2;
	init(le, mid, node*2);
	init(mid+1, ri, node*2+1);
	vector<int> temp;
	int lidx, ridx;
	lidx=ridx=0;
	while(lidx<tree[node*2].size()||ridx<tree[node*2+1].size()){
		if(ridx<tree[node*2+1].size()&&(lidx==tree[node*2].size()||tree[node*2+1][ridx]<tree[node*2][lidx])){
			temp.push_back(tree[node*2+1][ridx]);
			ridx++;
		}
		else{
			temp.push_back(tree[node*2][lidx]);
			lidx++;
		}
	}
	tree[node]=temp;
	return;
}
int query(int le, int ri, int nodele, int noderi,int node,  int x){
	if(noderi<le||ri<nodele)
		return 0;
	if(le<=nodele&&noderi<=ri){
		return upper_bound(tree[node].begin(), tree[node].end(), x)-tree[node].begin();
	}
	int mid=(nodele+noderi)/2;
	return query(le, ri, nodele, mid, node*2, x)+query(le, ri, mid+1, noderi, node*2+1, x);
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++){
		int in;
		scanf("%d", &in);
		arr.push_back(in);
	}
	init(0, n-1, 1);
	for(int i=0;i<m;i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		int le, ri, mid, ans;
		le=-1e9, ri=1e9;
		while(le<=ri){
			mid=(le+ri)/2;
			if(query(a-1, b-1,0, n-1, 1,  mid)>=c){
				ans=mid;
				ri=mid-1;
			}
			else
				le=mid+1;
		}
		printf("%d\n", ans);
	}
	return 0;
}

