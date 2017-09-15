// =====================================================================================
// 
//       Filename:  1398.cpp
//        Created:  2017년 09월 15일 17시 26분 37초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> vec;
int solve(int idx, ll s){
	int temp=0;
	while(idx>=0&&idx%3!=2){
		temp+=s/vec[idx];
		s%=vec[idx];
		idx--;
	}
	if(idx==-1)
		return temp;
	int ret=0x3f3f3f3f;
	for(int i=0;i*vec[idx]<=s;i++)
		ret=min(ret, solve(idx-1, s-i*vec[idx])+i+temp);
	return ret;
}
int main(){
	for(ll r=1;r<=1e15;r*=10)
		vec.push_back(r);
	for(ll r=25;r<=1e15;r*=100)
		vec.push_back(r);
	sort(vec.begin(), vec.end());
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		ll n;
		scanf("%lld", &n);
		printf("%d\n", solve(vec.size()-1, n));
	}
	return 0;
}

