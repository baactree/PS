// =====================================================================================
// 
//       Filename:  11280.cpp
//        Created:  2017년 06월 02일 14시 18분 50초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[20006];
int vertex_num;
int dis[20005];
int scc_num;
int scc[20005];
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
		if(dis[there]==-1){
			int temp=dfs(there);
			ret=min(ret, temp);
		}
		else if(scc[there]==-1)
			ret=min(ret, dis[there]);
	}
	if(ret==dis[now]){
		while(true){
			int t=st.top();
			st.pop();
			scc[t]=scc_num;
			if(t==now)
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
	for(int i=2;i<=n*2+1;i++)
		if(dis[i]==-1)
			dfs(i);
	bool flag=false;
	for(int i=2;i<=n*2;i+=2)
		if(scc[i]==scc[i+1])
			flag=true;
	printf("%d\n", !flag);
	return 0;
}

