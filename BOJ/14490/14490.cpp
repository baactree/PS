// =====================================================================================
// 
//       Filename:  14490.cpp
//        Created:  2017년 05월 03일 13시 46분 45초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int gcd(int a, int b){
	return b?gcd(b, a%b):a;
}
int main(){
	scanf("%d:%d", &n, &m);
	int g=gcd(n, m);
	printf("%d:%d\n", n/g, m/g);
	return 0;
}

