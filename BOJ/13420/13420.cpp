// =====================================================================================
// 
//       Filename:  13420.cpp
//        Created:  2017년 03월 14일 17시 43분 31초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		long long a, b, c;
		char op[2], temp[2];
		scanf("%lld%s%lld%s%lld", &a, op, &b, temp, &c);
		if(op[0]=='+'){
			printf("%s\n", a+b==c?"correct":"wrong answer");
		}
		else if(op[0]=='-'){
			printf("%s\n", a-b==c?"correct":"wrong answer");
		}
		else if(op[0]=='*'){
			printf("%s\n", a*b==c?"correct":"wrong answer");
		}
		else{
			printf("%s\n", a/b==c?"correct":"wrong answer");

		}

	}
	return 0;
}

