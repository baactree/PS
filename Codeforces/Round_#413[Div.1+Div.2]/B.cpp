// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 05월 22일 23시 16분 02초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int p[200000];
int a[200000];
int b[200000];
int m;
bool trip[200000];
priority_queue<pair<int, int> > pq[4];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &p[i]);
	for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
		pq[a[i]].push({-p[i], i});
	}
	for(int i=0;i<n;i++){
		scanf("%d", &b[i]);
		pq[b[i]].push({-p[i], i});
	}
	scanf("%d", &m);
	for(int i=0;i<m;i++){
		int in;
		scanf("%d", &in);
		while(!pq[in].empty()&&trip[pq[in].top().second])
			pq[in].pop();
		if(pq[in].empty())
			printf("-1 ");
		else{
			auto a=pq[in].top();
			pq[in].pop();
			printf("%d ", -a.first);
			trip[a.second]=true;
		}
	}
	return 0;
}

