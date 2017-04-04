// =====================================================================================
// 
//       Filename:  5698.cpp
//        Created:  2017년 04월 05일 01시 48분 40초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
bool possi(const string &str){
	char st=str[0];
	if('a'<=st&&st<='z')
		st=st-'a'+'A';
	for(int i=1;i<str.size();i++){
		if(str[i-1]==' '){
			if(str[i]==st||str[i]==st-'A'+'a')
				continue;
			else
				return false;
		}
	}
	return true;
}
int main(){
	while(true){
		string t;
		getline(cin, t);
		if(t=="*")
			break;
		printf("%s\n", possi(t)?"Y":"N");
	}
	return 0;
}

