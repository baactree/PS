// =====================================================================================
// 
//       Filename:  1259.cpp
//        Created:  2017년 08월 29일 01시 22분 06초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
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
	while(scanf("%d", &n)!=EOF){
		if(n==0)
			break;
		string str=to_string(n);
		printf("%s\n", possi(str)?"yes":"no");
	}
	return 0;
}

