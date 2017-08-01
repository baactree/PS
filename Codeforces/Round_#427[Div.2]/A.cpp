// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 07월 31일 22시 56분 24초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int s, v1, v2, t1, t2;
int main(){
	scanf("%d%d%d%d%d", &s, &v1, &v2, &t1, &t2);
	int a=s*v1+t1*2;
	int b=s*v2+t2*2;
	if(a<b)
		printf("First\n");
	else if(a>b)
		printf("Second\n");
	else
		printf("Friendship\n");
	return 0;
}

