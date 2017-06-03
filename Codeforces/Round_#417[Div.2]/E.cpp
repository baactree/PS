// =====================================================================================
// 
//       Filename:  E.cpp
//        Created:  2017년 06월 02일 00시 35분 19초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100005];
int cnt[10000005];
bool color[100005];
bool leaf;
vector<int> adj[100005];
void dfs(int now, int col){
	color[now]=col;
	if(adj[now].size()==0)
		leaf=col;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		dfs(there, 1-col);
	}
}
int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &arr[i]);
	for(int i=2;i<=n;i++){
		int p;
		scanf("%d", &p);
		adj[p].push_back(i);
	}
	dfs(1, 0);
	long long x=0;
	long long b, a;
	b=a=0;
	for(int i=1;i<=n;i++)
		if(color[i]==leaf){
			x^=arr[i];
			b++;
		}
		else{
			cnt[arr[i]]++;
			a++;
		}
	long long ans=0;
	if(x==0){
		ans+=b*(b-1)/2;
		ans+=a*(a-1)/2;
	}
	for(int i=1;i<=n;i++){
		if(color[i]==leaf){
			x^=arr[i];
			if(x<10000005)
				ans+=cnt[x];
			x^=arr[i];
		}
	}
	printf("%lld\n", ans);
	return 0;
}

