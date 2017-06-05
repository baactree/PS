// =====================================================================================
// 
//       Filename:  11278.cpp
//        Created:  2017년 06월 05일 18시 11분 06초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[50];
int scc_num;
int scc[50];
int dis[50];
int vertex_num;
int ans[50];
stack<int> st;
void push(int a, int b){
	if(a<0)
		a=a*-2+1;
	else
		a*=2;
	if(b<0)
		b=b*-2+1;
	else
		b*=2;
	adj[a].push_back(b);
}
int dfs(int now){
	int ret=dis[now]=vertex_num++;
	st.push(now);
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		if(dis[there]==-1)
			ret=min(ret, dfs(there));
		else if(scc[there]==-1)
			ret=min(ret, dis[there]);
	}
	if(ret==dis[now]){
		while(true){
			int temp=st.top();
			st.pop();
			scc[temp]=scc_num;
			if(temp==now)
				break;
		}
		scc_num++;
	}
	return ret;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		a*=-1;
		push(a, b);
		a*=-1;
		b*=-1;
		push(b, a);
	}
	memset(dis, -1, sizeof(dis));
	memset(scc, -1, sizeof(scc));
	memset(ans, -1, sizeof(ans));
	for(int i=2;i<=n*2+1;i++)
		if(dis[i]==-1)
			dfs(i);
	for(int i=2;i<=n*2;i+=2)
		if(scc[i]==scc[i+1]){
			printf("0\n");
			return 0;
		}
	vector<pair<int, int> > order;
	for(int i=2;i<=n*2+1;i++){
		order.push_back({-scc[i], i});
	}
	sort(order.begin(), order.end());
	printf("1\n");
	for(int i=0;i<order.size();i++){
		int now=order[i].second;
		if(ans[now/2]!=-1)
			continue;
		ans[now/2]=now&1;
	}
	for(int i=1;i<=n;i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}

