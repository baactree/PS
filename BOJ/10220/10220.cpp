// =====================================================================================
// 
//       Filename:  10220.cpp
//        Created:  2017년 04월 28일 21시 24분 26초
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
		int n;
		scanf("%d", &n);
		int ans=0;
		if(n<=3||n==6)
			ans=0;
		else if(n==4)
			ans=2;
		else
			ans=1;
		printf("%d\n", ans);
	}
	return 0;
}

