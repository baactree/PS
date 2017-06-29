// =====================================================================================
// 
//       Filename:  13700.cpp
//        Created:  2017년 06월 29일 09시 57분 59초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, s, d, f, b, k;
bool p[100005];
int dist[100005];
int main(){
	scanf("%d%d%d%d%d%d", &n, &s, &d, &f, &b, &k);
	for(int i=0;i<k;i++){
		int in;
		scanf("%d", &in);
		p[in]=true;
	}
	memset(dist, -1, sizeof(dist));
	queue<int> q;
	q.push(s);
	dist[s]=0;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		if(now+f<=n&&dist[now+f]==-1&&!p[now+f]){
			q.push(now+f);
			dist[now+f]=dist[now]+1;
		}
		if(now-b>=1&&dist[now-b]==-1&&!p[now-b]){
			q.push(now-b);
			dist[now-b]=dist[now]+1;
		}
	}
	if(dist[d]==-1)
		printf("BUG FOUND\n");
	else
		printf("%d\n", dist[d]);
	return 0;
}

