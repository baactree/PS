
// =====================================================================================
// 
//       Filename:  11281.cpp
//        Created:  2017년 04월 09일 01시 30분 22초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[22000];
int scc[22000];
int trip[22000];
int ans[10001];
int sn, vn;
stack<int> st;
int dfs(int now){
	int ret=trip[now]=vn++;
	st.push(now);
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(trip[there]==-1){
			int temp=dfs(there);
			ret=min(ret, temp);
		}
		else if(scc[there]==-1){
			ret=min(ret, trip[there]);
		}
	}
	if(ret==trip[now]){
		while(true){
			int temp=st.top();
			st.pop();
			scc[temp]=sn;
			if(temp==now)
				break;
		}
		sn++;
	}
	return ret;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		if(a<0)
			a=(-a)*2+1;
		else
			a*=2;
		if(b<0)
			b=(-b)*2+1;
		else
			b*=2;
		if(a&1)
			adj[a-1].push_back(b);
		else
			adj[a+1].push_back(b);
		if(b&1)
			adj[b-1].push_back(a);
		else
			adj[b+1].push_back(a);
	}
	memset(trip, -1, sizeof(trip));
	memset(scc, -1, sizeof(scc));
	for(int i=2;i<=n*2+1;i++)
		if(trip[i]==-1)
			dfs(i);
	for(int i=2;i<=n*2;i+=2)
		if(scc[i]==scc[i+1]){
			printf("0\n");
			return 0;
		}
	printf("1\n");
	vector<pair<int, int> > order;
	for(int i=2;i<=n*2+1;i++)
		order.push_back({-scc[i], i});
	sort(order.begin(), order.end());
	memset(ans, -1, sizeof(ans));
	for(int i=0;i<order.size();i++){
		int now=order[i].second;
		if(ans[now/2]!=-1)
			continue;
		ans[now/2]=(now&1);
	}
	for(int i=1;i<=n;i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}

