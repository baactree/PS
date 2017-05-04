// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 05월 04일 10시 07분 27초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string str;
int main(){
	cin>>str;
	int le, ri;
	le=0;
	ri=str.size()-1;
	int cnt=0;
	while(le<=ri){
		if(str[le]!=str[ri])
			cnt++;
		le++;
		ri--;
	}
	if(str.size()&1)
		printf("%s\n", cnt<=1?"YES":"NO");
	else
		printf("%s\n", cnt==1?"YES":"NO");
	return 0;
}

