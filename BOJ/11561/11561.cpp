// =====================================================================================
// 
//       Filename:  11561.cpp
//        Created:  2017년 05월 30일 02시 20분 08초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
long long n;
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		scanf("%lld", &n);
		typedef long long ll;
		ll le, ri, mid, ans;
		ans=0;
		le=0;
		ri=1e9;
		while(le<=ri){
			mid=(le+ri)/2;
			if(mid*(mid+1)/2<=n){
				ans=mid;
				le=mid+1;
			}
			else
				ri=mid-1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

