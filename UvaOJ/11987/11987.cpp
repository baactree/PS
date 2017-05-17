// =====================================================================================
// 
//       Filename:  11987.cpp
//        Created:  2017년 05월 14일 20시 54분 41초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int par[200005];
int cnt[200005];
long long sum[200005];
int n, m;
int find(int x){
	if(par[x]==x)
		return x;
	return par[x]=find(par[x]);
}
void merge(int x, int y){
	x=find(x);
	y=find(y);
	if(x==y)
		return;
	cnt[x]+=cnt[y];
	sum[x]+=sum[y];
	par[y]=x;
}
void move(int x, int y){
	int t=find(x);
	y=find(y);
	if(t==y)
		return;
	cnt[t]--;
	sum[t]-=x;
	par[x]=y;
	cnt[y]++;
	sum[y]+=x;
}
int main(){
	while(scanf("%d%d", &n, &m)!=EOF){
		for(int i=1;i<=n;i++){
			par[i]=par[i+n]=i+n;
			cnt[i]=cnt[i+n]=1;
			sum[i+n]=sum[i+n]=i;
		}
		for(int i=0;i<m;i++){
			int a;
			scanf("%d", &a);
			if(a==1){
				int p, q;
				scanf("%d%d", &p, &q);
				merge(p, q);
			}
			else if(a==2){
				int p, q;
				scanf("%d%d", &p, &q);
				move(p, q);
			}
			else{
				int p;
				scanf("%d", &p);
				p=find(p);
				printf("%d %lld\n", cnt[p], sum[p]);
			}
		}
	}
	return 0;
}

