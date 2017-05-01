// =====================================================================================
// 
//       Filename:  1329.cpp
//        Created:  2017년 05월 01일 23시 16분 16초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int par[200005];
int dist[200005];
int n;
int find(int x){
	if(par[x]==x)
		return x;
	int ret=find(par[x]);
	dist[x]+=dist[par[x]];
	return par[x]=ret;
}
int main(){
	int TestCase;
	scanf("%d", &TestCase);
	while(TestCase--){
		scanf("%d", &n);
		for(int i=1;i<=n;i++){
			par[i]=i;
			dist[i]=0;
		}
		while(true){
			char order[2];
			scanf("%s", order);
			if(order[0]=='O')
				break;
			if(order[0]=='E'){
				int a;
				scanf("%d", &a);
				find(a);
				printf("%d\n", dist[a]);
			}
			else{
				int a, b;
				scanf("%d%d", &a, &b);
				par[a]=b;
				dist[a]=abs(a-b)%1000;
			}
		}
	}
	return 0;
}

