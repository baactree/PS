// =====================================================================================
// 
//       Filename:  10425.cpp
//        Created:  2017년 06월 14일 02시 18분 48초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
const int p1=1e9;
const int p2=1e9+9;
map<int, int> mp;
int dp1[100005];
int dp2[100005];
int main(){
	dp1[0]=dp2[0]=0;
	dp1[1]=dp2[1]=1;
	for(int i=2;i<100005;i++){
		dp1[i]=(dp1[i-1]+dp1[i-2])%p1;
		mp[dp1[i]]=i;
	}
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		string str;
		cin>>str;
		str=string(max(str.begin(), str.end()-9), str.end());
		printf("%d\n", mp[stoi(str)]);
	}
	return 0;
}

