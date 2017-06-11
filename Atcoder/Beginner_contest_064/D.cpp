// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 06월 10일 21시 08분 24초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
string s;
string le, ri;
int main(){
	cin>>n>>s;
	le=ri="";
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='(')
			cnt++;
		else{
			if(cnt>0){
				cnt--;
			}
			else
				le+="(";
		}
	}
	for(int i=0;i<cnt;i++)
		ri+=")";
	cout<<le+s+ri<<endl;
	return 0;
}

