// =====================================================================================
// 
//       Filename:  14570.cpp
//        Created:  2017년 06월 09일 16시 01분 54초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
long long k;
vector<int> adj[200005];
int solve(int now, long long t){
	if(adj[now].size()==0)
		return now;
	if(adj[now].size()==1)
		return solve(adj[now][0], t);
	if(t&1)
		return solve(adj[now][0], t/2+1);
	return solve(adj[now][1], t/2);
}
int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		if(a!=-1)
			adj[i].push_back(a);
		if(b!=-1)
			adj[i].push_back(b);
	}
	scanf("%lld", &k);
	printf("%d\n", solve(1, k));
	return 0;
}

