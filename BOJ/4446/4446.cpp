// =====================================================================================
// 
//       Filename:  4446.cpp
//        Created:  2017년 09월 14일 17시 45분 08초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string a("aiyeou");
string A("AIYEOU");
string b("bkxznhdcwgpvjqtsrlmf");
string B("BKXZNHDCWGPVJQTSRLMF");
char trans[300];
int main(){
	string str;
	for(int i=0;i<300;i++)
		trans[i]=i;
	for(int i=0;i<6;i++){
		trans[a[i]]=a[(i+3)%6];
		trans[A[i]]=A[(i+3)%6];
	}
	for(int i=0;i<20;i++){
		trans[b[i]]=b[(i+10)%20];
		trans[B[i]]=B[(i+10)%20];
	}
	while(getline(cin, str)){
		for(int i=0;i<str.size();i++){
			printf("%c", trans[str[i]]);
		}
		printf("\n");
	}
	return 0;
}

