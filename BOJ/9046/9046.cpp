// =====================================================================================
// 
//       Filename:  9046.cpp
//        Created:  2017년 06월 03일 23시 18분 01초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int cnt[26];
int main(){
	int testcase;
	scanf("%d\n", &testcase);
	while(testcase--){
		memset(cnt, 0, sizeof(cnt));
		string str;
		getline(cin, str);
		for(int i=0;i<str.size();i++){
			if(str[i]>='a'&&str[i]<='z')
				cnt[str[i]-'a']++;
		}
		int max_cnt=-1;
		int idx;
		int pp=0;
		for(int i=0;i<26;i++){
			if(max_cnt<cnt[i]){
				max_cnt=cnt[i];
				idx=i;
				pp=0;
			}
			else if(max_cnt==cnt[i]){
				pp++;
			}
		}
		printf("%c\n", pp?'?':(idx+'a'));
	}
	return 0;
}

