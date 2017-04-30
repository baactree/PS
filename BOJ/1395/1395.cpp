// =====================================================================================
// 
//       Filename:  1395.cpp
//        Created:  2017년 04월 30일 16시 14분 12초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
class Sgtree{
	public:
	vector<pair<int, int> > tree;
	Sgtree(int n){
		tree.resize(n*4);
	}
	void update(int le, int ri, int nodele, int noderi, int node){
		if(tree[node].second!=0){
			if(tree[node].second&1)
				tree[node].first=(noderi-nodele+1)-tree[node].first;
			if(nodele!=noderi){
				tree[node*2].second+=tree[node].second;
				tree[node*2+1].second+=tree[node].second;
			}
			tree[node].second=0;
		}
		if(le>noderi||ri<nodele)
			return;
		if(le<=nodele&&noderi<=ri){
			tree[node].first=(noderi-nodele+1)-tree[node].first;
			if(nodele!=noderi){
				tree[node*2].second++;
				tree[node*2+1].second++;
			}
			return;
		}
		int mid=(nodele+noderi)/2;
		update(le, ri, nodele, mid, node*2);
		update(le, ri, mid+1, noderi, node*2+1);
		tree[node].first=tree[node*2].first+tree[node*2+1].first;
	}
	int query(int le, int ri, int nodele, int noderi, int node){
		if(tree[node].second!=0){
			if(tree[node].second&1)
				tree[node].first=(noderi-nodele+1)-tree[node].first;
			if(nodele!=noderi){
				tree[node*2].second+=tree[node].second;
				tree[node*2+1].second+=tree[node].second;
			}
			tree[node].second=0;
		}
		if(le>noderi||ri<nodele)
			return 0;
		if(le<=nodele&&noderi<=ri)
			return tree[node].first;
		int mid=(nodele+noderi)/2;
		return query(le, ri, nodele, mid, node*2)+query(le, ri, mid+1, noderi, node*2+1);
	
	}
};
int n, m;
int main(){
	scanf("%d%d", &n, &m);
	Sgtree sgtree(n);
	for(int i=0;i<m;i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if(!a){
			sgtree.update(b, c, 1, n, 1);
		}
		else{
			printf("%d\n", sgtree.query(b, c, 1, n, 1 ));

		}
	}
	return 0;
}

