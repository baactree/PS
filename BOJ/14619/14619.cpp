// =====================================================================================
// 
//       Filename:  14619.cpp
//        Created:  2017년 05월 31일 18시 28분 48초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m, t;
int mat[100][100];
int dist[100][100][2];
int h[100];
const int inf=0x3f3f3f3f;
int main(){
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++)
		scanf("%d", &h[i]);
	for(int i=0;i<m;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		mat[a][b]=mat[b][a]=1;
	}
	memset(dist, 0x3f, sizeof(dist));
	for(int i=1;i<=n;i++){
		queue<pair<int, pair<int, int> > > q;
		q.push({i, {0, 0}});
		while(!q.empty()){
			int now=q.front().first;
			int mode=q.front().second.first;
			int w=q.front().second.second;
			q.pop();
			for(int there=1;there<=n;there++){
				int next=1-mode;
				if(mat[now][there]&&dist[i][there][next]==inf){
					dist[i][there][next]=w+1;
					q.push({there, {next, w+1}});
				}
			}
		}
	}
	scanf("%d", &t);
	while(t--){
		int a, k;
		scanf("%d%d", &a, &k);
		int ans=inf;
		for(int i=1;i<=n;i++){
			if((k&1)&&dist[a][i][1]<=k)
				ans=min(ans, h[i]);
			if(k%2==0&&dist[a][i][0]<=k)
				ans=min(ans, h[i]);
		}
		printf("%d\n", ans==inf?-1:ans);
	}
	return 0;
}

