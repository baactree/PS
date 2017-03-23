// =====================================================================================
// 
//       Filename:  12813.cpp
//        Created:  2017년 03월 23일 11시 39분 29초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string a, b;
int main(){
	cin>>a>>b;
	for(int i=0;i<a.size();i++){
		a[i]-='0';
		b[i]-='0';
	}
	for(int i=0;i<a.size();i++)
		printf("%c", (a[i]&b[i])+'0');
	printf("\n");
	for(int i=0;i<a.size();i++)
		printf("%c", (a[i]|b[i])+'0');
	printf("\n");
	for(int i=0;i<a.size();i++)
		printf("%c", (a[i]^b[i])+'0');
	printf("\n");
	for(int i=0;i<a.size();i++)
		printf("%c", (1-a[i])+'0');
	printf("\n");
	for(int i=0;i<a.size();i++)
		printf("%c", (1-b[i])+'0');
	printf("\n");
	
	return 0;
}

