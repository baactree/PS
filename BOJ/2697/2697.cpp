// =====================================================================================
// 
//       Filename:  2697.cpp
//        Created:  2017년 05월 20일 12시 43분 17초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
char str[100];
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		scanf("%s", str);
		int len=strlen(str);
		if(next_permutation(str, str+len)){
			printf("%s\n", str);
		}
		else
			printf("BIGGEST\n");
	}
	return 0;
}

