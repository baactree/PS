// =====================================================================================
// 
//       Filename:  2975.cpp
//        Created:  2017년 05월 30일 22시 00분 50초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b;
	char c;
	while(true){
		scanf("%d %c %d", &a, &c, &b);
		if(a==0&&c=='W'&&b==0)
			break;
		if(c=='W'){
			if(a-b<-200)
				printf("Not allowed\n");
			else
				printf("%d\n", a-b);
		}
		else{
			printf("%d\n", a+b);
		}
	}
	return 0;
}

