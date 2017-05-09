// =====================================================================================
// 
//       Filename:  1342.cpp
//        Created:  2017년 05월 09일 15시 10분 10초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
string str;
int solve(int idx, int pre){
	if(idx==0)
		return 1;
	int ret=0;
	for(auto it=mp.begin();it!=mp.end();it++){
		if((it->second)>0&&it->first!=pre){
			(it->second)--;
			ret+=solve(idx-1, (it->first));
			(it->second)++;
		}
	}
	return ret;
}
int main(){
	cin>>str;
	for(int i=0;i<str.size();i++)
		mp[str[i]]++;
	printf("%d\n", solve(str.size(), 0));
	return 0;
}

