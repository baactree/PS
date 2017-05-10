// =====================================================================================
// 
//       Filename:  1322.cpp
//        Created:  2017년 04월 30일 21시 25분 39초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[64];
int ans[64];
int main(){
	ll x, k;
	scanf("%lld%lld", &x, &k);
	ll temp=x;
	int cnt=0;
	int idx=0;
	while(temp){
		arr[idx++]=temp&1;
		cnt+=temp&1;
		temp>>=1;
	}
	vector<int> t;
	temp=k;
	while(temp){
		t.push_back(temp&1);
		temp>>=1;
	}
	int tidx=0;
	for(int i=0;i<64;i++){
		if(arr[i]==0&&tidx<t.size())
			ans[i]=t[tidx++];
	}
	ll out=0;
	ll r=1;
	for(int i=0;i<64;i++){
		out+=ans[i]*r;
		r*=2;
	}
	printf("%lld\n", out);

	return 0;
}

