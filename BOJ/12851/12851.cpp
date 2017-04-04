// =====================================================================================
// 
//       Filename:  12851.cpp
//        Created:  2017년 04월 05일 01시 05분 18초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
int trip[100001];
int dist[100001];
int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	memset(dist, -1, sizeof(dist));
	queue<int> q;
	trip[n]=1;
	dist[n]=0;
	q.push(n);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		if(now*2<=100000){
			if(dist[now*2]==-1||dist[now*2]==dist[now]+1)
				trip[now*2]+=trip[now];
			if(dist[now*2]==-1){
				dist[now*2]=dist[now]+1;
				q.push(now*2);
			}
		}
		if(now+1<=100000){
			if(dist[now+1]==-1||dist[now+1]==dist[now]+1)
				trip[now+1]+=trip[now];
			if(dist[now+1]==-1){
				dist[now+1]=dist[now]+1;
				q.push(now+1);
			}
		}
		if(now-1>=0){
			if(dist[now-1]==-1||dist[now-1]==dist[now]+1)
				trip[now-1]+=trip[now];
			if(dist[now-1]==-1){
				dist[now-1]=dist[now]+1;
				q.push(now-1);
			}
		}
	}
	printf("%d\n%d\n", dist[k], trip[k]);
	return 0;
}

