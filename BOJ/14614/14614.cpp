// =====================================================================================
// 
//       Filename:  14614.cpp
//        Created:  2017년 06월 09일 15시 59분 42초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int a, b;
string c;
int main(){
	cin>>a>>b>>c;
	int now=c.back()-'0';
	if(now&1)
		printf("%d\n", a^b);
	else
		printf("%d\n", a);

	return 0;
}

