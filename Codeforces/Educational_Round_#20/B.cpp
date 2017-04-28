// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 04월 29일 00시 17분 20초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[200005];
int dist[200005];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	queue<int> q;
	memset(dist, -1, sizeof(dist));
	for(int i=0;i<n;i++){
		if(arr[i]==0){
			q.push(i);
			dist[i]=0;
		}
	}
	while(!q.empty()){
		int now=q.front();
		q.pop();
		if(now+1<n&&dist[now+1]==-1){
			dist[now+1]=dist[now]+1;
			q.push(now+1);
		}
		if(now-1>=0&&dist[now-1]==-1){
			dist[now-1]=dist[now]+1;
			q.push(now-1);
		}
	

	}
	for(int i=0;i<n;i++)
		printf("%d ", dist[i]);
	printf("\n");
	return 0;
}

