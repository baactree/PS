// =====================================================================================
// 
//       Filename:  3135.cpp
//        Created:  2017년 04월 08일 12시 46분 59초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int dist[1000];
int a, b;
int n;
int arr[5];
int main(){
	scanf("%d%d", &a, &b);
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	memset(dist, -1, sizeof(dist));
	queue<int> q;
	q.push(a);
	dist[a]=0;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		if(now-1>0&&dist[now-1]==-1){
			dist[now-1]=dist[now]+1;
			q.push(now-1);
		}
		if(now+1<=1000&&dist[now+1]==-1){
			dist[now+1]=dist[now]+1;
			q.push(now+1);
		}
		for(int i=0;i<n;i++){
			int there=arr[i];
			if(dist[there]==-1){
				dist[there]=dist[now]+1;
				q.push(there);
			}
		}
	}
	printf("%d\n", dist[b]);
	return 0;
}

