// =====================================================================================
// 
//       Filename:  10258.cpp
//        Created:  2017년 03월 19일 19시 04분 06초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int solve(string str);
int solve2(string str){
	if(str.size()==0)
		return 0;
	if(str.size()==1)
		return str=="0";
	if(str[0]=='1')
		return solve(string(str.begin()+1, str.end()));
	string next(str.size()-1, '0');
	next[0]='1';
	return solve2(string(str.begin()+1, str.end()))+1+solve(next);
}
int solve(string str){
	if(str.size()==0)
		return 0;
	if(str.size()==1){
		return str=="1";
	}
	if(str[0]=='0')
		return solve(string(str.begin()+1, str.end()));
	string next(str.size()-1, '0');
	next[0]='1';
	return pow(2, str.size()-1)+solve2(string(str.begin()+1, str.end()));
}
int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		string str;
		cin>>str;
		printf("%d\n", solve(str));
	}
	return 0;
}

