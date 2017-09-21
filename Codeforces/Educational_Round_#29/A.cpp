// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 09월 22일 00시 07분 59초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int x;
bool possi(string str){
	int le, ri;
	le=0;
	ri=str.size()-1;
	while(le<=ri)
		if(str[le++]!=str[ri--])
			return false;
	return true;
}
int main(){
	scanf("%d", &x);
	string str=to_string(x);
	string q="";
	for(int i=str.size()-1;i>=0;i--){
		if(str[i]=='0')
			q+='0';
		else
			break;
	}
	q+=str;
	printf("%s\n", possi(q)?"YES":"NO");
	return 0;
}

