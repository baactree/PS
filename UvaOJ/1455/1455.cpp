// =====================================================================================
// 
//       Filename:  1455.cpp
//        Created:  2017년 05월 05일 16시 35분 39초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
struct Node{
	int first, second;
	Node(){}
	Node(int first, int second):first(first), second(second){}
	Node operator + (Node &rhs)const{
		return {first+rhs.first, second+rhs.second};
	}
};
vector<Node> tree;
int n, m;
int par[100001];
int miny[100001];
int maxy[100001];
int cnt[100001];
pair<int, int> arr[100001];
int find(int x){
	if(par[x]==x)
		return x;
	return par[x]=find(par[x]);
}
void update(vector<Node>& tree, int idx, Node val){
	idx++;
	while(idx<2000005){
		tree[idx]=tree[idx]+val;
		idx+=idx&(-idx);
	}
}
Node query(vector<Node>& tree, int idx){
	idx++;
	Node ret={0, 0};
	while(idx){
		ret=ret+tree[idx];
		idx-=idx&(-idx);
	}
	return ret;
}
int main(){
	int TestCase;
	scanf("%d", &TestCase);
	while(TestCase--){
		scanf("%d", &n);
		tree=vector<Node> (2000005, {0, 0});
		for(int i=1;i<=n;i++){
			scanf("%d%d", &arr[i].first, &arr[i].second);
			arr[i].first*=2;
			arr[i].second*=2;
			miny[i]=maxy[i]=arr[i].second;
			cnt[i]=1;
			par[i]=i;
			update(tree, arr[i].second, {1, 1});
			update(tree, arr[i].second+1, {-1, -1});
		}
		scanf("%d", &m);
		for(int i=0;i<m;i++){
			char order[10];
			scanf("%s", order);
			if(order[0]=='l'){
				double c;
				scanf("%lf", &c);
				int k=c*2+1e-9;
				Node ans=query(tree, k);
				printf("%d %d\n", ans.second, ans.first);
			}
			else{
				int a, b;
				scanf("%d%d", &a, &b);
				a++;b++;
				a=find(a);
				b=find(b);
				if(a!=b){
					int now=cnt[a];
					update(tree, miny[a], {-now, -1});
					update(tree, maxy[a]+1, {now, 1});
					now=cnt[b];
					update(tree, miny[b], {-now, -1});
					update(tree, maxy[b]+1, {now, 1});
					par[a]=b;
					cnt[b]+=cnt[a];
					miny[b]=min(miny[b], miny[a]);
					maxy[b]=max(maxy[b], maxy[a]);
					update(tree, miny[b], {cnt[b], 1});
					update(tree, maxy[b]+1, {-cnt[b], -1});
				}
			}
		}
	}
	return 0;
}

