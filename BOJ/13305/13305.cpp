// =====================================================================================
// 
//       Filename:  13305.cpp
//        Created:  2017년 04월 23일 20시 29분 03초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int dist[100000];
int cost[100000];
int main(){
	scanf("%d", &n);
	for(int i=0;i+1<n;i++)
		scanf("%d", &dist[i]);
	for(int i=0;i<n;i++)
		scanf("%d", &cost[i]);
	int st=0;
	int now=0;
	long long ans=0;
	while(now!=n-1){
		if(cost[st]<=cost[now]){
			ans+=(long long)dist[now]*cost[st];
			now++;
		}
		else{
			st=now;
			ans+=(long long)dist[now]*cost[st];
			now++;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

