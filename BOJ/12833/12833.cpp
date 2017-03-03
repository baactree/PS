// =====================================================================================
// 
//       Filename:  12833.cpp
//        Created:  2017년 01월 17일 14시 58분 56초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int A, B, C;
	scanf("%d%d%d", &A, &B, &C);
	printf("%d\n", C&1?A^B:A);
	return 0;
}

