// =====================================================================================
// 
//       Filename:  11505.cpp
//        Created:  2017년 05월 11일 19시 32분 13초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m, k;
const int mod=1000000007;
typedef long long ll;
ll tree[4000000];
int sz;
void update(int idx, int val){
	idx+=sz;
	tree[idx]=val;
	idx/=2;
	while(idx){
		tree[idx]=(tree[idx*2]*tree[idx*2+1])%mod;
		idx/=2;
	}
}
int query(int le, int ri){
	le+=sz;
	ri+=sz;
	int ret=1;
	while(le<=ri){
		if(le&1){
			ret=(ret*tree[le])%mod;
			le++;
		}
		if(!(ri&1)){
			ret=(ret*tree[ri])%mod;
			ri--;
		}
		le/=2;
		ri/=2;
	}
	return ret;
}
int main(){
	scanf("%d%d%d", &n, &m, &k);
	sz=1;
	while(sz<n)
		sz*=2;
	for(int i=0;i<n;i++){
		int in;
		scanf("%d", &in);
		update(i, in);
	}
	for(int i=0;i<m+k;i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if(a==1)
			update(b-1, c);
		else{
			if(b>c)
				swap(b, c);
			printf("%d\n", query(b-1, c-1));
		}
	}
	return 0;
}

