// =====================================================================================
// 
//       Filename:  E.cpp
//        Created:  2017년 05월 27일 19시 51분 22초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
struct Node{
	int cnt;
	int l[10], r[10];
	Node(){
		cnt=0;
		for(int i=0;i<10;i++)
			l[i]=r[i]=0;
	}
};
int n, m, q;
Node tree[400000];
int mat[10][100000];
int par[1000000];
int pidx;
int find(int x){
	if(x==par[x])
		return x;
	return par[x]=find(par[x]);
}
int merge(int x, int y){
	x=find(x);
	y=find(y);
	if(x==y)
		return 0;
	par[x]=y;
	return -1;
}
Node mergetree(Node le, Node ri, int idx){
	Node ret;
	ret.cnt=le.cnt+ri.cnt;
	for(int i=0;i<n;i++){
		par[le.l[i]]=le.l[i];
		par[le.r[i]]=le.r[i];
		par[ri.l[i]]=ri.l[i];
		par[ri.r[i]]=ri.r[i];
	}
	for(int i=0;i<n;i++){
		if(mat[i][idx]==mat[i][idx+1])
			ret.cnt+=merge(le.r[i], ri.l[i]);
	}
	for(int i=0;i<n;i++){
		ret.l[i]=find(le.l[i]);
		ret.r[i]=find(ri.r[i]);
	}
	return ret;
}
void init(int le, int ri, int node){
	if(le==ri){
		for(int i=0;i<n;i++)
			if(i==0||mat[i][le]!=mat[i-1][le]){
				tree[node].cnt++;
				tree[node].r[i]=tree[node].l[i]=pidx++;
			}
			else
				tree[node].r[i]=tree[node].l[i]=tree[node].r[i-1];
		return;
	}
	int mid=(le+ri)/2;
	init(le, mid, node*2);
	init(mid+1, ri, node*2+1);
	tree[node]=mergetree(tree[node*2], tree[node*2+1], mid);
}
Node query(int le, int ri, int nodele, int noderi, int node){
	if(le<=nodele&&noderi<=ri)
		return tree[node];
	int mid=(nodele+noderi)/2;
	if(mid<le)
		return query(le, ri, mid+1, noderi, node*2+1);
	if(ri<=mid)
		return query(le, ri, nodele, mid, node*2);
	return mergetree(query(le, ri, nodele, mid, node*2), query(le, ri, mid+1, noderi, node*2+1), mid);
}
int main(){
	scanf("%d%d%d", &n, &m, &q);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d", &mat[i][j]);
	init(0, m-1, 1);
	while(q--){
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", query(a-1, b-1, 0, m-1, 1).cnt);
	}
	return 0;
}
