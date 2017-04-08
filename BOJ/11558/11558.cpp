// =====================================================================================
// 
//       Filename:  11558.cpp
//        Created:  2017년 04월 07일 16시 01분 09초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int edge[10001];
int n;
int trip[10001];
int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		scanf("%d", &n);
		for(int i=1;i<=n;i++)
			scanf("%d", &edge[i]);
		memset(trip, -1, sizeof(trip));
		trip[1]=0;
		queue<int> q;
		q.push(1);
		while(!q.empty()){
			int now=q.front();
			q.pop();
			if(trip[edge[now]]==-1){
				trip[edge[now]]=trip[now]+1;
				q.push(edge[now]);
			}
		}
		printf("%d\n", trip[n]==-1?0:trip[n]);
	}
	return 0;
}

