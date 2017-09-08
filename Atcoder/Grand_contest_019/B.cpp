// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 09월 08일 04시 31분 22초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int cnt[26];
int main(){
	string str;
	cin>>str;
	long long ans=1;
	for(int i=0;i<str.size();i++){
		ans+=i-cnt[str[i]-'a'];
		cnt[str[i]-'a']++;
	}
	cout<<ans<<endl;
	return 0;
}

