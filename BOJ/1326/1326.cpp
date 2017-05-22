// =====================================================================================
// 
//       Filename:  1326.cpp
//        Created:  2017년 05월 22일 16시 13분 02초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int a, b;
int arr[10005];
int dist[10005];
int main(){
	memset(dist, -1, sizeof(dist));
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &arr[i]);
	scanf("%d%d", &a, &b);
	queue<int> q;
	q.push(a);
	dist[a]=0;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int there=now+arr[now];there<=n;there+=arr[now]){
			if(dist[there]==-1){
				dist[there]=dist[now]+1;
				q.push(there);
			}
		}
		for(int there=now-arr[now];there>0;there-=arr[now]){
			if(dist[there]==-1){
				dist[there]=dist[now]+1;
				q.push(there);
			}
		}
	}
	printf("%d\n", dist[b]);
	return 0;
}

