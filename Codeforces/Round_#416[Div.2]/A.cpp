// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 05월 27일 18시 07분 18초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int a, b;
int main(){
	scanf("%d%d", &a, &b);
	int n=1;
	int turn=0;
	while(true){
		if((n&1)&&a-n<0){
			printf("Vladik\n");
			return 0;
		}
		if(n%2==0&&b-n<0){
			printf("Valera\n");
			return 0;
		}
		if(n&1)
			a-=n;
		else
			b-=n;
		n++;
	}
	return 0;
}

