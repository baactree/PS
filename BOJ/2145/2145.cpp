// =====================================================================================
// 
//       Filename:  2145.cpp
//        Created:  2017년 09월 18일 23시 37분 10초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n==0)
			break;
		while(n>=10){
			int next=0;
			while(n){
				next+=n%10;
				n/=10;
			}
			n=next;
		}
		printf("%d\n", n);
	}
	return 0;
}

