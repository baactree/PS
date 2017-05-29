// =====================================================================================
// 
//       Filename:  3778.cpp
//        Created:  2017년 05월 29일 20시 49분 46초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int cnt[26];
char a[1000];
char b[1000];
int main(){
	int n;
	scanf("%d\n", &n);
	for(int tc=1;tc<=n;tc++){
		fgets(a, 1000, stdin);
		fgets(b, 1000, stdin);
		int len=strlen(a);
		for(int i=0;i<len;i++)
			cnt[a[i]-'a']++;
		len=strlen(b);
		for(int i=0;i<len;i++)
			cnt[b[i]-'a']--;
		int ans=0;
		for(int i=0;i<26;i++){
			ans+=abs(cnt[i]);
			cnt[i]=0;
		}
		printf("Case #%d: %d\n",tc,  ans);
	}
	return 0;
}

