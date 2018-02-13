#include <bits/stdc++.h>
using namespace std;
struct Sgtree{
	int n;
	vector<vector<int> > tree;
	Sgtree(){}
	Sgtree(const vector<int> &arr){
		n=arr.size();
		tree.resize(n*4);
		init(arr,0,n-1,1);
	}
	void init(const vector<int> &arr,int nodele,int noderi,int node){
		if(nodele==noderi){
			tree[node].push_back(arr[nodele]);
			return;
		}
		int mid=(nodele+noderi)/2;
		init(arr,nodele,mid,node*2);
		init(arr,mid+1,noderi,node*2+1);
		for(auto x:tree[node*2])
			tree[node].push_back(x);
		for(auto x:tree[node*2+1])
			tree[node].push_back(x);
		sort(tree[node].begin(),tree[node].end());
	}
	int query(int le,int ri,int x,int nodele,int noderi,int node){
		if(le>noderi||ri<nodele)
			return 0;
		if(le<=nodele&&noderi<=ri){
			int idx=upper_bound(tree[node].begin(),tree[node].end(),x)-tree[node].begin();
			return (int)tree[node].size()-idx;
		}
		int mid=(nodele+noderi)/2;
		return query(le,ri,x,nodele,mid,node*2)+query(le,ri,x,mid+1,noderi,node*2+1);
	}
	int query(int le,int ri,int x){
		return query(le,ri,x,0,n-1,1);
	}
};
int n,m;
vector<int> arr;
int main(){
	scanf("%d",&n);
	arr.resize(n+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	Sgtree sgt(arr);
	int ans=0;
	scanf("%d",&m);
	while(m--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		a^=ans;
		b^=ans;
		c^=ans;
		ans=sgt.query(a,b,c);
		printf("%d\n",ans);
	}
	return 0;
}