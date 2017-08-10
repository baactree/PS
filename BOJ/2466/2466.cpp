// =====================================================================================
// 
//       Filename:  2466.cpp
//        Created:  2017년 08월 10일 23시 39분 11초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int dp[100005];
struct Sgtree{
	int n;
	pair<int, pair<int, int> > tree[400005];
	Sgtree(){}
	Sgtree(int n):n(n){
		memset(tree, 0x3f, sizeof(tree));
	}
	void update(int le, int ri, pair<int, int> val, int nodele, int noderi, int node){
		if(tree[node].second.second!=inf){
			tree[node].first=dp[nodele]+tree[node].second.second;
			if(nodele!=noderi){
				tree[node*2].second=min(tree[node*2].second, tree[node].second);
				tree[node*2+1].second=min(tree[node*2+1].second, tree[node].second);
			}
			tree[node].second.second=inf;
		}
		if(le>noderi||ri<nodele)
			return;
		if(le<=nodele&&noderi<=ri){
			tree[node].first=dp[nodele]+val.second;
			if(nodele!=noderi){
				tree[node*2].second=min(tree[node*2].second, val);
				tree[node*2+1].second=min(tree[node*2+1].second, val);
			}
			return;
		}
		int mid=(nodele+noderi)/2;
		update(le, ri, val, nodele, mid, node*2);
		update(le, ri, val, mid+1, noderi, node*2+1);
		tree[node].first=min(tree[node*2].first, tree[node*2+1].first);
	}
	void update(int le, int ri, pair<int, int> val){
		update(le, ri, val, 0, n-1, 1);
	}
	int query(int le, int ri, int nodele, int noderi, int node){
		if(tree[node].second.second!=inf){
			tree[node].first=dp[nodele]+tree[node].second.second;
			if(nodele!=noderi){
				tree[node*2].second=min(tree[node*2].second, tree[node].second);
				tree[node*2+1].second=min(tree[node*2+1].second, tree[node].second);
			}
			tree[node].second.second=inf;
		}
		if(le>noderi||ri<nodele)
			return inf;
		if(le<=nodele&&noderi<=ri)
			return tree[node].first;
		int mid=(nodele+noderi)/2;
		return min(query(le, ri, nodele, mid, node*2), query(le, ri, mid+1, noderi, node*2+1));
	}
	int query(int le, int ri){
		return query(le, ri, 0, n-1, 1);
	}
};
int n;
int t[100005], h[100005];
int pre[100005], sum[100005];
bool possi(int x){
	Sgtree sgt(n);
	int cnt=0;
	for(int i=1;i<=n;i++){
		int k=lower_bound(sum, sum+i, sum[i]-x)-sum;
		if(k==i)
			return false;
		int j=max(k, pre[i]);
		sgt.update(j, i-1, {cnt--, h[i]});
		dp[i]=sgt.query(k, i-1);
	}
	return dp[n]<=x;
}
int main(){
	scanf("%d", &n);
	stack<int> st;
	for(int i=1;i<=n;i++){
		scanf("%d%d", &t[i], &h[i]);
		sum[i]=sum[i-1]+t[i];	
		while(!st.empty()&&h[st.top()]<=h[i])
			st.pop();
		if(st.empty())
			pre[i]=0;
		else
			pre[i]=st.top();
		st.push(i);
	}
	int le, ri, mid, ans;
	le=0;
	ri=3500000;
	while(le<=ri){
		mid=(le+ri)/2;
		if(possi(mid)){
			ans=mid;
			ri=mid-1;
		}
		else
			le=mid+1;
	}
	printf("%d\n", ans);
	return 0;
}

