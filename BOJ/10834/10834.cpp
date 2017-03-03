// =====================================================================================
// 
//       Filename:  10834.cpp
//        Created:  2017년 02월 22일 15시 31분 03초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int m;
int main(){
	bool s = false;
	int r=1;
	scanf("%d", &m);
	for(int i=0;i<m;i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if(c)
			s=!s;
		r=r/a*b;
	}
	printf("%d %d\n", s, r);
	return 0;
}

