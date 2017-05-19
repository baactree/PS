// =====================================================================================
// 
//       Filename:  4921.cpp
//        Created:  2017년 05월 19일 18시 03분 39초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
vector<char> adj[255];
bool connect(char a, char b){
	for(int i=0;i<adj[a].size();i++){
		char there=adj[a][i];
		if(b==there)
			return true;
	}
	return false;
}
bool possi(const string &str){
	if(str[0]=='1'&&str.back()=='2'){
		int cnt=0;
		for(int i=0;i+1<str.size();i++){
			if(str[i]=='5')
				cnt++;
			if(str[i]=='6')
				cnt--;
			if(!connect(str[i], str[i+1]))
				return false;
		}
		return cnt==0;
	}
	return false;
}
int main(){
	adj['1'].push_back('4');
	adj['1'].push_back('5');
	adj['3'].push_back('4');
	adj['3'].push_back('5');
	adj['4'].push_back('2');
	adj['4'].push_back('3');
	adj['5'].push_back('8');
	adj['6'].push_back('2');
	adj['6'].push_back('3');
	adj['7'].push_back('8');
	adj['8'].push_back('7');
	adj['8'].push_back('6');

	int tc=0;
	string str;
	while(cin>>str){
		tc++;
		if(str=="0")
			break;
		printf("%d. %s\n", tc, possi(str)?"VALID":"NOT");
	}
	return 0;
}

