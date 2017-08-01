// =====================================================================================
// 
//       Filename:  9521.cpp
//        Created:  2017년 08월 01일 15시 16분 14초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
long long n, k;
int adj[1000005];
int st[1000005], fi[1000005];
int vn, sn;
const int mod=1e9+7;
int cnt=0;
long long ans=1;
long long f[1000005];
void dfs(int now){
	st[now]=++vn;
	int there=adj[now];
	if(!st[there])
		dfs(there);
	else if(st[there]&&!fi[there]){
		int k=st[now]-st[there]+1;
		ans*=f[k];
		ans%=mod;
		cnt+=k;
	}
	fi[now]=true;
}
int main(){
	scanf("%lld%lld", &n, &k);
	f[1]=k;
	f[2]=(k*(k-1))%mod;
	f[3]=(k*(k-1)*(k-2))%mod;
	for(int i=4;i<=n;i++){
		f[i]=f[i-1]*(k-2)+f[i-2]*(k-1);
		f[i]%=mod;
	}
	for(int i=1;i<=n;i++)
		scanf("%d", &adj[i]);
	for(int i=1;i<=n;i++)
		if(!st[i])
			dfs(i);
	for(int i=0;i<n-cnt;i++){
		ans*=k-1;
		ans%=mod;
	}
	printf("%lld\n", ans);
	return 0;
}

