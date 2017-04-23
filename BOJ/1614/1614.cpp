// =====================================================================================
// 
//       Filename:  1614.cpp
//        Created:  2017년 04월 23일 21시 38분 28초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
long long n, k;
int main(){
	scanf("%lld%lld", &n, &k);
	long long ans=0;
	if(n==1){
		ans+=k*8;
	}
	else if(n==2){
		ans++;
		if(k&1){
			ans+=6;
		}
		k/=2;
		ans+=k*8;
	}
	else if(n==3){
		ans+=2;
		ans+=k*4;
	}
	else if(n==4){
		ans+=3;
		if(k&1)
			ans+=2;
		k/=2;
		ans+=k*8;
	}
	else if(n==5){
		ans+=4;
		ans+=k*8;
	}
	printf("%lld\n", ans);
	return 0;
}

