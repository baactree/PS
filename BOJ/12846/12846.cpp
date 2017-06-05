// =====================================================================================
// 
//       Filename:  12846.cpp
//        Created:  2017년 06월 05일 18시 03분 25초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
pair<int, int> tree[400005];
int sz;
int n;
typedef long long ll;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
void update(int idx, pair<int, int> val){
	idx+=sz;
	while(idx){
		tree[idx]=min(tree[idx], val);
		idx/=2;
	}
}
pair<int, int> query(int a, int b){
	pair<int, int> ret={inf, inf};
	a+=sz;
	b+=sz;
	while(a<=b){
		if(a&1){
			ret=min(ret, tree[a]);
			a++;
		}
		if(!(b&1)){
			ret=min(ret, tree[b]);
			b--;
		}
		a/=2;
		b/=2;
	}
	return ret;
}
ll solve(int le, int ri){
	if(le>ri)
		return -linf;
	if(le==ri){
		return query(le, ri).first;
	}
	auto idx=query(le, ri);
	ll ret=idx.first*(ri-le+1);
	ret=max(ret, solve(le, idx.second-1));
	ret=max(ret, solve(idx.second+1, ri));
	return ret;
}
int main(){
	for(int i=0;i<400005;i++)
		tree[i]={inf, inf};
	scanf("%d", &n);
	sz=1;
	while(sz<n)
		sz*=2;
	for(int i=0;i<n;i++){
		int in;
		scanf("%d", &in);
		update(i, {in, i});
	}
	printf("%lld\n", solve(0, n-1));
	return 0;
}

