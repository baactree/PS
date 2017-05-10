// =====================================================================================
// 
//       Filename:  9375.cpp
//        Created:  2017년 05월 08일 16시 13분 22초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int TestCase;
	scanf("%d", &TestCase);
	while(TestCase--){
		int n;
		scanf("%d", &n);
		map<string, long long> mp;
		for(int i=0;i<n;i++){
			string a, b;
			cin>>a>>b;
			mp[b]++;
		}
		long long cnt=mp.size();
		long long ans=1;
		for(auto it=mp.begin();it!=mp.end();it++)
			ans*=((it->second)+1);
		printf("%lld\n", ans-1);
	}
	return 0;
}

