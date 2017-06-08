// =====================================================================================
// 
//       Filename:  12761.cpp
//        Created:  2017년 06월 08일 15시 23분 22초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int dist[100005];
int n, m;
int a, b;
bool safe(int x){
	return x>=0&&x<=100000;
}
int main(){
	scanf("%d%d", &a, &b);
	scanf("%d%d", &n, &m);
	memset(dist, -1, sizeof(dist));
	dist[n]=0;
	queue<int> q;
	q.push(n);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		if(safe(now+1)&&dist[now+1]==-1){
			dist[now+1]=dist[now]+1;
			q.push(now+1);
		}
		if(safe(now-1)&&dist[now-1]==-1){
			dist[now-1]=dist[now]+1;
			q.push(now-1);
		}
		if(safe(now+a)&&dist[now+a]==-1){
			dist[now+a]=dist[now]+1;
			q.push(now+a);
		}
		if(safe(now-a)&&dist[now-a]==-1){
			dist[now-a]=dist[now]+1;
			q.push(now-a);
		}
		if(safe(now+b)&&dist[now+b]==-1){
			dist[now+b]=dist[now]+1;
			q.push(now+b);
		}
		if(safe(now-b)&&dist[now-b]==-1){
			dist[now-b]=dist[now]+1;
			q.push(now-b);
		}
		if(safe(now*a)&&dist[now*a]==-1){
			dist[now*a]=dist[now]+1;
			q.push(now*a);
		}
		if(safe(now*b)&&dist[now*b]==-1){
			dist[now*b]=dist[now]+1;
			q.push(now*b);
		}
	}
	printf("%d\n", dist[m]);
	return 0;
}

