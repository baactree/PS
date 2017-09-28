// =====================================================================================
// 
//       Filename:  E.cpp
//        Created:  2017년 09월 25일 00시 55분 59초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef long long ld;
ld cache[11][100][1<<10][2];
ll p[11][100];
ld solve(int b, int idx, int k, int mode){
	if(idx==0)
		return k==0&&mode;
	ld &ret=cache[b][idx][k][mode];
	if(ret!=-1)
		return ret;
	ret=0;
	if(mode){
		for(int i=0;i<b;i++)
			ret+=solve(b, idx-1, k^(1<<i), 1);
	}
	else{
		for(int i=1;i<b;i++)
			ret+=solve(b, idx-1, k^(1<<i), 1);
		ret+=solve(b, idx-1, k, 0);
	}
	return ret;
}
ld calc(int idx, int b, ld x, int k, int mode){
	if(idx==0)
		return x==0&&k==0&&mode;
	ll tt=x/p[b][idx-1];
	ld ret=0;
	if(mode){
		for(int i=0;i<tt;i++)
			ret+=solve(b, idx-1, k^(1<<i), 1);
	}
	else{
		for(int i=1;i<tt;i++)
			ret+=solve(b, idx-1, k^(1<<i), 1);
		ret+=solve(b, idx-1, k, 0);
	}
	return ret+calc(idx-1, b, x%p[b][idx-1], k^(1<<tt), 1);
}
int get_idx(ld x, int b){
	int ret=1;
	ll r=1;
	while(r*b<=x){
		r*=b;
		ret++;
	}
	return ret;
}
int main(){
	for(int i=2;i<=10;i++){
		p[i][0]=1;
		for(int j=1;p[i][j-1]*i<=1000000000000000000ll;j++)
			p[i][j]=p[i][j-1]*i;
	}
	memset(cache, -1, sizeof(cache));
	int q;
	scanf("%d", &q);
	while(q--){
		int b;
		ld l, r;
		scanf("%d%lld%lld", &b, &l, &r);
		ld t1=calc(get_idx(r, b), b, r, 0, 0);
		ld t2=calc(get_idx(l-1, b), b, l-1, 0, 0);
		printf("%lld\n", t1-t2);
	}
	return 0;
}

