// =====================================================================================
// 
//       Filename:  7489.cpp
//        Created:  2017년 04월 29일 13시 11분 39초
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
		long long temp=1;
		for(int i=1;i<=n;i++){
			temp*=i;
			while(temp%10==0)
				temp/=10;
			temp%=100000000;
		}
		printf("%lld\n", temp%10);
	}
	return 0;
}

