// =====================================================================================
// 
//       Filename:  2479.cpp
//        Created:  2017년 04월 03일 11시 22분 46초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> adj[1001];
bool trip[1001];
int par[1001];
char str[1001][31];
void print(int now){
	if(now==0)
		return;
	print(par[now]);
	printf("%d ", now);
}
int main(){
	scanf("%d%d", &n, &k);
	for(int i=1;i<=n;i++){
		scanf("%s", str[i]);
	}
	int st, fi;
	scanf("%d%d", &st, &fi);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			int cnt=0;
			for(int q=0;q<k;q++)
				if(str[i][q]!=str[j][q])
					cnt++;
			if(cnt==1){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	queue<int> q;
	trip[st]=true;
	q.push(st);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<adj[now].size();i++){
			int there=adj[now][i];
			if(!trip[there]){
				q.push(there);
				trip[there]=true;
				par[there]=now;
			}
		}
	}
	if(!trip[fi])
		printf("-1\n");
	else{
		print(fi);
	}
	return 0;
}

