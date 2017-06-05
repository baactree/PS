// =====================================================================================
// 
//       Filename:  13306.cpp
//        Created:  2017년 06월 05일 17시 46분 30초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
struct query{
	int a, b, c;
};
int par[200005];
int p[200005];
int n, m;
query q[400005];
int ans[400005];
int find(int x){
	if(x==par[x])
		return x;
	return par[x]=find(par[x]);
}
void merge(int x, int y){
	x=find(x);
	y=find(y);
	if(x==y)
		return;
	par[x]=y;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++)
		par[i]=i;
	for(int i=2;i<=n;i++)
		scanf("%d", &p[i]);
	for(int i=0;i<n-1+m;i++){
		int a;
		scanf("%d", &a);
		if(a==0){
			int b;
			scanf("%d", &b);
			q[i]={a, b, 0};
		}
		else{
			int b, c;
			scanf("%d%d", &b, &c);
			q[i]={a, b, c};
		}
	}
	for(int i=n-1+m-1;i>=0;i--){
		if(q[i].a==0){
			merge(q[i].b, p[q[i].b]);	
		}
		else{
			int u, v;
			u=q[i].b;
			v=q[i].c;
			u=find(u);
			v=find(v);
			if(u==v)
				ans[i]=2;
			else
				ans[i]=1;
		}
	}
	for(int i=0;i<n-1+m;i++)
		if(ans[i]==2)
			printf("YES\n");
		else if(ans[i]==1)
			printf("NO\n");
	return 0;
}

