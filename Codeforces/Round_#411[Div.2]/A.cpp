// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 05월 04일 23시 28분 03초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int l, r;
int main(){
	scanf("%d%d", &l, &r);
	if(l==r&&l&1){
		printf("%d\n", l);
		return 0;
	}
	printf("2\n");
	return 0;
}

