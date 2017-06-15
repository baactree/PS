// =====================================================================================
// 
//       Filename:  14579.cpp
//        Created:  2017년 06월 15일 04시 29분 07초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
const int mod=14579;
int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	int ans=1;
	for(int i=a;i<=b;i++){
		ans=((long long)ans*((i*(i+1))/2))%mod;
	}
	printf("%d\n", ans);
	return 0;
}

