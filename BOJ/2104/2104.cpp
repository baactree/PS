// =====================================================================================
// 
//       Filename:  2104.cpp
//        Created:  2017년 05월 25일 23시 47분 36초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100005];
typedef long long ll;
ll sum[100005];
pair<int, int> tree[400005];
const int inf=0x3f3f3f3f;
int sz;
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
		return 0;
	if(le==ri)
		return (ll)arr[le]*arr[le];
	auto idx=query(le, ri);
	ll ret=(sum[ri]-sum[le-1])*idx.first;
	ret=max(ret, solve(le, idx.second-1));
	ret=max(ret, solve(idx.second+1, ri));
	return ret;
}
int main(){
	memset(tree, 0x3f, sizeof(tree));
	scanf("%d", &n);
	sz=1;
	while(sz<n)
		sz*=2;
	for(int i=1;i<=n;i++){
		scanf("%d", &arr[i]);
		sum[i]=sum[i-1]+arr[i];
		update(i, {arr[i], i});
	}
	printf("%lld\n", solve(1, n));
	return 0;
}

