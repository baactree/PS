// =====================================================================================
// 
//       Filename:  10539.cpp
//        Created:  2017년 04월 05일 01시 53분 19초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	long long sum=0;
	int n;
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		long long in;
		scanf("%lld", &in);
		printf("%lld ", in*i-sum);
		sum+=in*i-sum;
	}
	return 0;
}

