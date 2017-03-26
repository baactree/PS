// =====================================================================================
// 
//       Filename:  1343.cpp
//        Created:  2017년 03월 26일 20시 34분 35초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string str;
string ans;
vector<string> vec;
void solve(int idx){
	if(idx==str.size()){
		cout<<ans<<endl;
		exit(0);
		return;
	}
	if(str[idx]=='.')
		solve(idx+1);
	else{
		if(idx+3<str.size()&&string(str.begin()+idx, str.begin()+idx+4)=="XXXX"){
			for(int i=idx;i<idx+4;i++)
				ans[i]='A';
			solve(idx+4);
		}
		if(idx+1<str.size()&&string(str.begin()+idx, str.begin()+idx+2)=="XX"){
			ans[idx]=ans[idx+1]='B';
			solve(idx+2);
		}
	}
}
int main(){
	cin>>str;
	ans=str;
	solve(0);
	printf("-1\n");
	return 0;
}

