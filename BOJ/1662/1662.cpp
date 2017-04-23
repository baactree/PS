// =====================================================================================
// 
//       Filename:  1662.cpp
//        Created:  2017년 04월 23일 22시 30분 37초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string str;
int solve(string now){
	int ret=0;
	for(int i=0;i<now.size();i++){
		if(now[i]=='('){
			ret--;
			int cnt=1;
			int fi;
			for(int j=i+1;j<now.size();j++){
				if(now[j]=='(')
					cnt++;
				else if(now[j]==')')
					cnt--;
				if(cnt==0){
					fi=j;
					break;
				}
			}
			int k=now[i-1]-'0';
			ret+=k*solve(string(now.begin()+i+1,now.begin()+fi));
			i=fi;
		}
		else
			ret++;
	}
	return ret;
}
int main(){
	cin>>str;
	printf("%d\n", solve(str));
	return 0;
}

