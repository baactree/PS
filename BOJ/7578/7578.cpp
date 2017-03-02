// =====================================================================================
// 
//       Filename:  7578.cpp
//        Created:  2017년 03월 02일 13시 26분 23초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int idx[1000001];
int n;
int tree[500005];
void update(int idx){
	while(idx<500005){
		tree[idx]++;
		idx+=idx&(-idx);
	}
}
int query(int idx){
	int ret=0;
	while(idx>0){
		ret+=tree[idx];
		idx-=idx&(-idx);
	}
	return ret;
}
int main(){
	scanf("%d", &n);
	int cnt=0;
	for(int i=0;i<n;i++){
		int in;
		scanf("%d", &in);
		idx[in]=++cnt;
	}
	long long ans=0;
	for(int i=0;i<n;i++){
		int in;
		scanf("%d", &in);
		ans+=i-query(idx[in]);
		update(idx[in]);
	}
	printf("%lld\n", ans);
	return 0;
}

