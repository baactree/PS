// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 03월 31일 12시 39분 33초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	int cnt = 0;
	while (true) {
		cnt++;
		a *= 3;
		b *= 2;
		if (a > b)
			break;
	}
	printf("%d\n", cnt);
	return 0;
}
