// =====================================================================================
// 
//       Filename:  13913.cpp
//        Created:  2017년 04월 23일 12시 07분 32초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int dist[100001];
int n, k;
int par[100001];
int main(){
	scanf("%d%d", &n, &k);
	memset(par, -1, sizeof(par));
	memset(dist, -1, sizeof(dist));
	queue<int> q;
	q.push(n);
	dist[n]=0;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		if(now+1<=100000&&dist[now+1]==-1){
			dist[now+1]=dist[now]+1;
			par[now+1]=now;
			q.push(now+1);
		}
		if(now-1>=0&&dist[now-1]==-1){
			dist[now-1]=dist[now]+1;
			par[now-1]=now;
			q.push(now-1);
		}
		if(now*2<=100000&&dist[now*2]==-1){
			dist[now*2]=dist[now]+1;
			par[now*2]=now;
			q.push(now*2);
		}
	}
	printf("%d\n", dist[k]);
	int temp=k;
	stack<int> st;
	while(temp!=-1){
		st.push(temp);
		temp=par[temp];
	}
	while(!st.empty()){
		int now=st.top();
		printf("%d ", now);
		st.pop();
	}
	return 0;
}

