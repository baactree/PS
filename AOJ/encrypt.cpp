// =====================================================================================
// 
//       Filename:  encrypt.cpp
//        Created:  2017년 02월 21일 16시 20분 55초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int Case;
	cin>>Case;
	while(Case--){
		string str;
		cin>>str;
		for(int i=0;i<str.size();i+=2)
			printf("%c", str[i]);
		for(int i=1;i<str.size();i+=2)
			printf("%c", str[i]);
		printf("\n");
	}
	return 0;
}

