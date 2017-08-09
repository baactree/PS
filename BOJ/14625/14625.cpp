// =====================================================================================
// 
//       Filename:  14625.cpp
//        Created:  2017년 08월 10일 00시 58분 37초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int sh, sm, eh, em, d;
int main(){
	cin>>sh>>sm>>eh>>em>>d;
	int ans=0;
	while(true){
		if(sh/10==d||sh%10==d||sm/10==d||sm%10==d)
			ans++;
		if(sh==eh&&sm==em)
			break;
		sm++;
		if(sm==60){
			sh++;
			sm=0;
		}
	}
	printf("%d\n", ans);
	return 0;
}

