// =====================================================================================
// 
//       Filename:  2268.cpp
//        Created:  2017년 05월 05일 11시 06분 55초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> tree;
int sz;
ll arr[1000001];
void update(int b, int c){
	b+=sz;
	while(b){
		tree[b]+=c;
		b/=2;
	}
}
ll query(int a, int b){
	a+=sz;
	b+=sz;
	ll ret=0;
	while(a<=b){
		if(a&1){
			ret+=tree[a];
			a++;
		}
		if(!(b&1)){
			ret+=tree[b];
			b--;
		}
		a/=2;
		b/=2;
	}
	return ret;
}
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	sz=1;
	while(sz<n)
		sz<<=1;
	sz<<=1;
	tree.resize(sz);
	sz/=2;
	for(int i=0;i<m;i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if(a==1){
			ll diff=c-arr[b];
			arr[b]=c;
			update(b, diff);
		}
		else{
			if(b>c)
				swap(b, c);
			printf("%lld\n", query(b, c));
		}
	}
	return 0;
}

