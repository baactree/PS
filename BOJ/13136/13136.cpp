// =====================================================================================
// 
//       Filename:  13136.cpp
//        Created:  2017년 03월 26일 18시 59분 08초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int r, c, n;
	scanf("%d%d%d", &r, &c, &n);
	printf("%lld\n", (long long)(ceil((double)r/n)*ceil((double)c/n)));
	return 0;
}

