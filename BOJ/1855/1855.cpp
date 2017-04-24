// =====================================================================================
// 
//       Filename:  1855.cpp
//        Created:  2017년 04월 24일 11시 18분 23초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int k;
string str;
int main(){
	cin>>k>>str;
	for(int i=k;i<str.size();i+=k*2){
		reverse(str.begin()+i, str.begin()+i+k);
	}
	for(int j=0;j<k;j++)
		for(int i=0;i<str.size()/k;i++)
			printf("%c", str[i*k+j]);
	return 0;
}

