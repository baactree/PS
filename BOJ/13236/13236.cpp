// =====================================================================================
// 
//       Filename:  13236.cpp
//        Created:  2017년 06월 26일 17시 13분 51초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d", &n);
	while(true){
		printf("%d ", n);
		if(n==1)
			break;
		if(n&1){
			n*=3;
			n++;
		}
		else{
			n/=2;
		}
	}
	return 0;
}

