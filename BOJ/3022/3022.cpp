// =====================================================================================
// 
//       Filename:  3022.cpp
//        Created:  2017년 08월 01일 14시 33분 30초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
map<string, int> mp;
int main(){
	scanf("%d", &n);
	int sum=0;
	int ans=0;
	while(n--){
		string in;
		cin>>in;
		if(sum-mp[in]<mp[in])
			ans++;
		mp[in]++;
		sum++;
	}
	printf("%d\n", ans);
	return 0;
}

