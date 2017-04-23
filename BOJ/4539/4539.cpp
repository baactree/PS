// =====================================================================================
// 
//       Filename:  4539.cpp
//        Created:  2017년 04월 23일 19시 14분 21초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int TestCase;
	scanf("%d", &TestCase);
	while(TestCase--){
		int x;
		scanf("%d", &x);
		int p=10;
		while(x>p){
			x+=p/10*5;
			x/=p;
			x*=p;
			p*=10;
		}
		printf("%d\n", x);
	}
	return 0;
}

