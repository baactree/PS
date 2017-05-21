// =====================================================================================
// 
//       Filename:  3944.cpp
//        Created:  2017년 05월 21일 13시 43분 14초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		int b;
		scanf("%d ", &b);
		char c='0';
		int ans=0;
		while(true){
			c=getchar();
			if(!(c>='0'&&c<='9'))
				break;
			ans+=(c-'0')%(b-1);
			ans%=b-1;
		}
		printf("%d\n", ans);
	}
	return 0;
}

