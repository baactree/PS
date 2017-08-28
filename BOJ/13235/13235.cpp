// =====================================================================================
// 
//       Filename:  13235.cpp
//        Created:  2017년 08월 29일 01시 24분 07초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
bool possi(string str){
	int le=0;
	int ri=str.size()-1;
	while(le<=ri){
		if(str[le]!=str[ri])
			return false;
		le++;
		ri--;
	}
	return true;
}
int main(){
	string str;
	cin>>str;
	printf("%s\n", possi(str)?"true":"false");
	return 0;
}

