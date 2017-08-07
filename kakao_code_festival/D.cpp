// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 08월 05일 15시 20분 24초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> mp;
int solve(int b, int g){
	if(b>=20)
		return 0;
	if(g==1)
		return b==0;
	if(g<=1)
		return 0;
	if(mp.count({b, g})!=0)
		return mp[{b, g}];
	mp[{b, g}]=solve(b+1, g-1);
	if(b>1&&g%3==0)
		mp[{b, g}]+=solve(b-2, g/3);
	return mp[{b, g}];
}
int solution(int n) {
	return solve(0,n);
}
int main(){
	int k;
	scanf("%d", &k);
	cout<<solution(k)<<endl;
	return 0;
}

