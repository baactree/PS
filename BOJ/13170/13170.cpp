// =====================================================================================
// 
//       Filename:  13170.cpp
//        Created:  2017년 06월 12일 17시 14분 25초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k, p, w;
int main(){
	scanf("%d%d%d%d", &n, &k, &p, &w);
	printf("%d\n", (p+w-1)/w);
	return 0;
}

