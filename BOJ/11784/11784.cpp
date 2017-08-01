// =====================================================================================
// 
//       Filename:  11784.cpp
//        Created:  2017년 07월 31일 17시 07분 38초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string str;
string calc(string t){
	int p;
	sscanf(t.c_str(), "%x", &p);
	string ret="";
	ret+=(char)p;
	return ret;
}
int main(){
	while(getline(cin, str)){
		string ans="";
		for(int i=0;i<str.size();i+=2){
			ans+=calc(string(str.begin()+i, str.begin()+i+2));
		}
		cout<<ans<<'\n';
	}
	return 0;
}

