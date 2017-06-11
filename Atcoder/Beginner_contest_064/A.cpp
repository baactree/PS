// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 06월 10일 20시 55분 16초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main(){
	scanf("%d%d%d", &a, &b, &c);
	int out=a*100+b*10+c;
	printf("%s\n", (out%4==0)?"YES":"NO");
	return 0;
}

