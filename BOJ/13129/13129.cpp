// =====================================================================================
// 
//       Filename:  13129.cpp
//        Created:  2017년 05월 19일 17시 59분 36초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int a, b, n;
int main(){
	scanf("%d%d%d", &a, &b, &n);
	for(int i=0;i<n;i++)
		printf("%d ", a*n+b*(i+1));
	return 0;
}

