// =====================================================================================
// 
//       Filename:  12756.cpp
//        Created:  2017년 03월 19일 21시 55분 22초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int aa, ah, ba, bh;
int main(){
	cin>>aa>>ah>>ba>>bh;
	while(ah>0&&bh>0){
		ah-=ba;
		bh-=aa;
	}
	if(ah>0)
		printf("PLAYER A\n");
	else if(bh>0)
		printf("PLAYER B\n");
	else
		printf("DRAW\n");
	return 0;
}

