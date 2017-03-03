// =====================================================================================
// 
//       Filename:  1919.cpp
//        Created:  2017년 01월 17일 15시 01분 50초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int cnt[26];
string a, b;
int main(){
	cin>>a>>b;
	for(int i=0;i<a.size();i++)
		cnt[a[i]-'a']++;
	for(int i=0;i<b.size();i++)
		cnt[b[i]-'a']--;
	int ans=0;
	for(int i=0;i<26;i++)
		ans+=abs(cnt[i]);
	printf("%d\n", ans);
	return 0;
}

