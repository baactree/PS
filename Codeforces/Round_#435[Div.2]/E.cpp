// =====================================================================================
// 
//       Filename:  E.cpp
//        Created:  2017년 09월 21일 00시 06분 02초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int a[100005], b[100005];
typedef long long ll;
ll inf=0x3f3f3f3f3f3f3f3f;
vector<ll> vec;
ll query(ll s){
	ll ret=inf;
	int idx=lower_bound(vec.begin(), vec.end(), -s)-vec.begin();
	if(idx<vec.size())
		ret=min(ret, abs(vec[idx]+s));
	if(idx+1<vec.size())
		ret=min(ret, abs(vec[idx+1]+s));
	if(idx-1>=0)
		ret=min(ret, abs(vec[idx-1]+s));
	return ret;
}
int main(){
	scanf("%d%d%d", &n, &m, &q);
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);
	for(int i=0;i<m;i++)
		scanf("%d", &b[i]);
	ll as=0;
	for(int i=0;i<n;i++)
		if(i&1)
			as-=a[i];
		else
			as+=a[i];
	ll bs=0;
	for(int i=0;i<n;i++){
		if(i&1)
			bs+=b[i];
		else
			bs-=b[i];
	}
	vec.push_back(bs);
	for(int i=n;i<m;i++){
		bs+=b[i-n];
		bs=-bs;
		if(n&1)
			bs-=b[i];
		else
			bs+=b[i];
		vec.push_back(bs);
	}
	sort(vec.begin(), vec.end());
	printf("%lld\n", query(as));
	while(q--){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		int len=b-a+1;
		int even=b/2-a/2+(a%2==0);
		int odd=len-even;
		as+=((ll)odd-even)*c;
		printf("%lld\n", query(as));
	}
	return 0;
}

