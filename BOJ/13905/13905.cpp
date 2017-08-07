// =====================================================================================
// 
//       Filename:  13905.cpp
//        Created:  2017년 08월 03일 03시 02분 10초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int> > adj[100005];
bool trip[100005];
bool possi(int s, int t, int x){
	memset(trip, 0, sizeof(trip));
	queue<int> q;
	q.push(s);
	trip[s]=true;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<adj[now].size();i++){
			int there=adj[now][i].first;
			int capacity=adj[now][i].second;
			if(capacity<x||trip[there])
				continue;
			trip[there]=true;
			q.push(there);
		}
	}
	return trip[t];
}
int main(){
	scanf("%d%d", &n, &m);
	int s, t;
	scanf("%d%d", &s, &t);
	for(int i=0;i<m;i++){
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		adj[a].push_back({b, d});
		adj[b].push_back({a, d});
	}
	int le, ri, mid, ans;
	le=0;
	ri=1e6;
	ans=0;
	while(le<=ri){
		mid=(le+ri)/2;
		if(possi(s, t, mid)){
			ans=mid;
			le=mid+1;
		}
		else
			ri=mid-1;
	}
	printf("%d\n", ans);
	return 0;
}

