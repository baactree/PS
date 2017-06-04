// =====================================================================================
// 
//       Filename:  2481.cpp
//        Created:  2017년 06월 04일 18시 34분 02초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int node[100005];
char input[50];
map<int, int> mp;
vector<int> adj[100005];
int par[100005];
bool trip[100005];
int main(){
	scanf("%d%d", &n, &k);
	for(int i=1;i<=n;i++){
		scanf("%s", input);
		int r=1;
		int now=0;
		for(int j=k-1;j>=0;j--, r*=2)
			if(input[j]=='1')
				now+=r;
		mp[now]=i;
		node[i]=now;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<k;j++){
			node[i]^=(1<<j);
			if(mp.count(node[i])!=0){
				adj[i].push_back(mp[node[i]]);
			}
			node[i]^=(1<<j);
		}
	}
	queue<int> q;
	q.push(1);
	trip[1]=true;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<adj[now].size();i++){
			int there=adj[now][i];
			if(!trip[there]){
				trip[there]=true;
				par[there]=now;
				q.push(there);
			}
		}
	}
	scanf("%d", &m);
	for(int i=0;i<m;i++){
		int in;
		scanf("%d", &in);
		if(!trip[in]){
			printf("-1\n");
			continue;
		}
		stack<int> st;
		int now=in;
		while(now!=0){
			st.push(now);
			now=par[now];
		}
		while(!st.empty()){
			printf("%d ", st.top());
			st.pop();
		}
		printf("\n");
	}
	return 0;
}

