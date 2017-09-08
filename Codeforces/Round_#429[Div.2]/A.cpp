// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 09월 08일 03시 24분 41초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
string str;
int cnt[26];
int main(){
	scanf("%d%d", &n, &k);
	cin>>str;
	for(int i=0;i<n;i++){
		cnt[str[i]-'a']++;
		if(cnt[str[i]-'a']>k)
			return !printf("NO\n");
	}
	printf("YES\n");
	return 0;
}

