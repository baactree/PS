// =====================================================================================
// 
//       Filename:  1043.cpp
//        Created:  2017년 05월 28일 19시 37분 51초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> p;
vector<int> party[55];
bool used[55];
int par[55];
int cnt[55];
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
	cnt[y]+=cnt[x];
	par[x]=y;
}
bool connect(int x){
	for(int i=0;i<p.size();i++){
		int a=find(x);
		int b=find(p[i]);
		if(a==b)
			return true;
	}
	return false;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++){
		par[i]=i;
		cnt[i]=1;
	}
	int k;
	scanf("%d", &k);
	for(int i=0;i<k;i++){
		int in;
		scanf("%d", &in);
		p.push_back(in);
	}
	for(int i=0;i<m;i++){
		scanf("%d", &k);
		for(int j=0;j<k;j++){
			int in;
			scanf("%d", &in);
			party[i].push_back(in);
		}
	}
	for(int i=0;i<m;i++){
		for(int j=1;j<party[i].size();j++){
			merge(party[i][j], party[i][j-1]);
		}
	}
	int ans=0;
	for(int i=0;i<m;i++){
		int cnt=0;
		for(int j=0;j<party[i].size();j++){
			if(connect(party[i][j]))
				cnt++;
		}
		if(cnt==0)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}

