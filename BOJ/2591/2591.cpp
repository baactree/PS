// =====================================================================================
// 
//       Filename:  2591.cpp
//        Created:  2017년 02월 21일 15시 39분 59초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string str;
int n;
int cache[41];
int solve(int idx){
	if(idx==n)
		return 1;
	int &ret=cache[idx];
	if(ret!=-1)
		return ret;
	ret=0;
	if(str[idx]=='0')
		return ret;
	ret=solve(idx+1);
	if(idx+1<n&&(str[idx]<'3'||str[idx]=='3'&&str[idx+1]<'5'))
		ret+=solve(idx+2);
	return ret;
}
int main(){
	memset(cache, -1, sizeof(cache));
	cin>>str;
	n=str.size();
	printf("%d\n", solve(0));
	return 0;
}

