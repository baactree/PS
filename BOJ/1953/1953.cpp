// =====================================================================================
// 
//       Filename:  1953.cpp
//        Created:  2017년 07월 30일 21시 57분 09초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> adj[205];
int vn, sn, d[205], s[205];
int ans[205];
stack<int> st;
int dfs(int now){
	int ret=d[now]=vn++;
	st.push(now);
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(d[there]==-1)
			ret=min(ret, dfs(there));
		else if(s[there]==-1)
			ret=min(ret, d[there]);
	}
	if(ret==d[now]){
		while(true){
			int temp=st.top();
			st.pop();
			s[temp]=sn;
			if(temp==now)
				break;
		}
		sn++;
	}
	return ret;
}
int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d", &k);
		while(k--){
			int in;
			scanf("%d", &in);
			//(a or b) and (!a or !b)
			adj[i*2+1].push_back(in*2);
			adj[in*2+1].push_back(i*2);
			adj[i*2].push_back(in*2+1);
			adj[in*2].push_back(i*2+1);
		}
	}
	memset(d, -1, sizeof(d));
	memset(s, -1, sizeof(s));
	vn=sn=0;
	for(int i=1;i<=n;i++){
		if(d[i*2]==-1)
			dfs(i*2);
		if(d[i*2+1]==-1)
			dfs(i*2+1);
	}
	vector<pair<int, int> > order;
	for(int i=1;i<=n;i++){
		order.push_back({-s[i*2], i*2});
		order.push_back({-s[i*2+1], i*2+1});
	}
	sort(order.begin(), order.end());
	memset(ans, -1, sizeof(ans));
	for(int i=0;i<order.size();i++){
		int now=order[i].second;
		if(ans[now/2]!=-1)
			continue;
		ans[now/2]=(now&1);
	}
	vector<int> a;
	vector<int> b;
	for(int i=1;i<=n;i++)
		if(ans[i])
			a.push_back(i);
		else
			b.push_back(i);
	printf("%d\n", a.size());
	for(auto x:a)
		printf("%d ", x);
	printf("\n%d\n", b.size());
	for(auto x:b)
		printf("%d ", x);
	printf("\n");
	return 0;
}

