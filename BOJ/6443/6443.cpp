// =====================================================================================
// 
//       Filename:  6443.cpp
//        Created:  2017년 05월 30일 02시 08분 03초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
string str;
int cnt[52];
void solve(int idx, string &ans){
	if(idx==str.size()){
		cout<<ans<<'\n';
		return;
	}
	for(int i=0;i<52;i++){
		if(cnt[i]>0){
			cnt[i]--;
			if(i<26)
				ans+=(char)(i+'a');
			else
				ans+=(char)(i+'A'-26);
			solve(idx+1, ans);
			cnt[i]++;
			ans.pop_back();
		}
	}
}
int main(){
	scanf("%d", &n);
	while(n--){
		cin>>str;
		memset(cnt, 0, sizeof(cnt));
		for(int i=0;i<str.size();i++)
			if(str[i]>='a'&&str[i]<='z')
				cnt[str[i]-'a']++;
			else if(str[i]>='A'&&str[i]<='Z')
				cnt[str[i]-'A'+26]++;
		string t="";
		solve(0, t);
	}
	return 0;
}

