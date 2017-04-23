// =====================================================================================
// 
//       Filename:  5426.cpp
//        Created:  2017년 04월 23일 22시 21분 29초
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
		string str;
		cin>>str;
		int x=sqrt(str.size());
		for(int j=x-1;j>=0;j--)
			for(int i=0;i<x;i++){
				int now=i*x+j;
				printf("%c", str[now]);
			}
		printf("\n");
	}
	return 0;
}

