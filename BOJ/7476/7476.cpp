// =====================================================================================
// 
//       Filename:  7476.cpp
//        Created:  2017년 06월 06일 16시 01분 05초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
typedef long long ll;
ll a[501];
ll b[501];
int cache[501][501];
pair<int, int> path[501][501];
int solve(int aidx, int bidx){
	if(aidx==n+1||bidx==m+1)
		return 0;
	int &ret=cache[aidx][bidx];
	if(ret!=-1)
		return ret;
	ret=1;
	path[aidx][bidx]={-1, -1};
	for(int i=aidx+1;i<=n;i++){
		if(a[aidx]>=a[i])
			continue;
		for(int j=bidx+1;j<=m;j++){
			if(a[i]==b[j]){
				int temp=solve(i, j)+1;
				if(ret<temp){
					ret=temp;
					path[aidx][bidx]={i, j};
				}
				break;
			}
		}
	}
	return ret;
}
int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%lld", &a[i]);
	scanf("%d", &m);
	for(int i=1;i<=m;i++)
		scanf("%lld", &b[i]);
	a[0]=(-1ll)<<33;
	b[0]=(-1ll)<<33;
	memset(cache, -1, sizeof(cache));
	printf("%d\n", solve(0, 0)-1);
	auto now=path[0][0];
	while(now.first!=-1&&now.second!=-1){
		printf("%lld ", a[now.first]);
		now=path[now.first][now.second];
	}
	printf("\n");
	return 0;
}

