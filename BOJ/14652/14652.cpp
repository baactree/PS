// =====================================================================================
// 
//       Filename:  14652.cpp
//        Created:  2017년 07월 31일 17시 17분 48초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int main(){
	scanf("%d%d%d", &n, &m, &k);
	printf("%d %d\n", k/m, k%m);
	return 0;
}

