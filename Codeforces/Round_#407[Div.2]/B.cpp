// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 04월 02일 15시 10분 09초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll b, q, l, m;
ll arr[100000];
set<ll> s;
set<ll> use;
int main(){
	scanf("%lld%lld%lld%lld", &b, &q, &l, &m);
	for(int i=0;i<m;i++){
		ll in;
		scanf("%lld", &in);
		s.insert(in);
	}
	ll ans=0;
	if(q==-1){
		if(abs(b)<=l){
			if(s.find(b)!=s.end()&&s.find(-b)!=s.end())
				printf("0\n");
			else 
				printf("inf\n");
			return 0;
		}
		printf("0\n");
		return 0;
	}
	while(abs(b)<=l){
		if(use.find(b)!=use.end()){
			if(s.find(b)==s.end()){
				printf("inf\n");
				return 0;
			}
			else{
				break;
			}
		}
		if(s.find(b)==s.end())
			ans++;
		use.insert(b);
		b*=q;
		
	}
	printf("%lld\n", ans);
	return 0;
}

