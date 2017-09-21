// =====================================================================================
// 
//       Filename:  E.cpp
//        Created:  2017년 09월 22일 00시 51분 22초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3f;
struct Sgtree{
	vector<pair<ll, ll> > tree;
	int n;
	Sgtree(){}
	Sgtree(int n):n(n){
		tree=vector<pair<ll, ll> >(n*4);
	}
	void update(int le, int ri, ll val, int nodele, int noderi, int node){
		if(tree[node].second!=0){
			tree[node].first+=tree[node].second;
			if(nodele!=noderi){
				tree[node*2].second+=tree[node].second;
				tree[node*2+1].second+=tree[node].second;
			}
			tree[node].second=0;
		}
		if(le>noderi||ri<nodele)
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
		tree[node].first=min(tree[node*2].first, tree[node*2+1].first);
	}
	void update(int le, int ri, ll val){
		update(le, ri, val, 0, n-1, 1);
	}
	ll query(int le, int ri, int nodele, int noderi, int node){
		if(tree[node].second!=0){
			tree[node].first+=tree[node].second;
			if(nodele!=noderi){
				tree[node*2].second+=tree[node].second;
				tree[node*2+1].second+=tree[node].second;
			}
			tree[node].second=0;
		}
		if(le>noderi||ri<nodele)
			return inf;
		if(le<=nodele&&noderi<=ri)
			return tree[node].first;
		int mid=(nodele+noderi)/2;
		return min(query(le, ri, nodele, mid, node*2), query(le, ri, mid+1, noderi, node*2+1));
	}
	ll query(int le, int ri){
		return query(le, ri, 0, n-1, 1);
	}
};
int n;
pair<int, int> arr[200005];
int main(){
	scanf("%d", &n);
	vector<int> xidx;
	for(int i=0;i<n;i++){
		scanf("%d%d", &arr[i].first, &arr[i].second);
		xidx.push_back(arr[i].first);
		xidx.push_back(arr[i].second);
		xidx.push_back(arr[i].second+1);
	}
	sort(xidx.begin(), xidx.end());
	xidx.erase(unique(xidx.begin(), xidx.end()), xidx.end());
	for(int i=0;i<n;i++){
		int idx=lower_bound(xidx.begin(), xidx.end(), arr[i].first)-xidx.begin();
		arr[i].first=idx;
		idx=lower_bound(xidx.begin(), xidx.end(), arr[i].second)-xidx.begin();
		arr[i].second=idx;
	}
	Sgtree sgt(xidx.size());
	for(int i=0;i<n;i++)
		sgt.update(arr[i].first, arr[i].second, 1);
	for(int i=0;i<n;i++){
		ll q=sgt.query(arr[i].first, arr[i].second);
		if(q>=2)
			return !printf("%d\n", i+1);
	}
	printf("-1\n");
	return 0;
}

