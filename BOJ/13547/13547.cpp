// =====================================================================================
// 
//       Filename:  13547.cpp
//        Created:  2017년 05월 14일 22시 05분 36초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
struct Query{
	int le, ri, idx;
};
int n, m;
int arr[100005];
Query q[100005];
int ans[100005];
int sz;
int cnt;
int num[1000005];
bool cmp(const Query &a, const Query &b){
	int as=a.le/sz;
	int bs=b.le/sz;
	if(as==bs)
		return a.ri<b.ri;
	return as<bs;
}
void insert(int x){
	num[x]++;
	if(num[x]==1)
		cnt++;
}
void erase(int x){
	if(num[x]==1)
		cnt--;
	num[x]--;
}
int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &arr[i]);
	scanf("%d", &m);
	for(int i=0;i<m;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		q[i]={a, b, i};
	}
	sz=sqrt(n);
	sort(q, q+m, cmp);
	int le, ri;
	le=ri=1;
	insert(arr[1]);
	for(int i=0;i<m;i++){
		int nle=q[i].le;
		int nri=q[i].ri;
		for(int j=le;j<nle;j++)
			erase(arr[j]);
		for(int j=nle;j<le;j++)
			insert(arr[j]);
		for(int j=ri+1;j<=nri;j++)
			insert(arr[j]);
		for(int j=nri+1;j<=ri;j++)
			erase(arr[j]);
		ans[q[i].idx]=cnt;
		le=nle;
		ri=nri;
	}
	for(int i=0;i<m;i++)
		printf("%d\n", ans[i]);
	return 0;
}

