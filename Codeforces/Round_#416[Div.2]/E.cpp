// =====================================================================================
// 
//       Filename:  E.cpp
//        Created:  2017년 05월 27일 19시 51분 22초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int mat[10][100000];
struct Query{
	int le, ri, idx;
};
Query qu[100005];
int ans[100005];
int sz;
int cnt;
bool trip[10][2];
bool cmp(const Query &a, const Query &b){
	int as=a.le/sz;
	int bs=b.le/sz;
	if(as==bs)
		return a.ri<b.ri;
	return as<bs;
}
void dfs(int x, int y){
	
}
void insert(int x){
	memset(trip, 0, sizeof(trip));
	if(x==0){

	}
}
void erase(int x){

}
int main(){
	scanf("%d%d%d", &n, &m, &q);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d", &mat[i][j]);
	for(int i=0;i<q;i++){
		scanf("%d%d", &qu[i].le, &qu[i].ri);
		qu[i].idx=i;
	}
	sz=sqrt(m);
	sort(qu, qu+q, cmp);
	int le, ri;
	le=ri=0;
	insert(0);
	for(int i=0;i<q;i++){
		int nle=qu[i].le;
		int nri=qu[i].ri;
		for(int j=le;j<nle;j++)
			erase(j);
		for(int j=nle;j<le;j++)
			insert(j);
		for(int j=ri+1;j<=nri;j++)
			insert(j);
		for(int j=nri+1;j<=ri;j++)
			erase(j);
		ans[qu[i].idx]=cnt;
		le=nle;
		ri=nri;
	}
	for(int i=0;i<q;i++)
		printf("%d\n", ans[i]);
	return 0;
}

