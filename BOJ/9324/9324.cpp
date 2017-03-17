// =====================================================================================
// 
//       Filename:  9324.cpp
//        Created:  2017년 03월 17일 16시 06분 20초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		string str;
		cin>>str;
		vector<int> cnt(26, 0);
		bool ans=false;
		for(int i=0;i<str.size();i++){
			cnt[str[i]-'A']++;
			if(cnt[str[i]-'A']%3==0){
				if(i+1==str.size()||str[i+1]!=str[i])
					ans=true;
				i++;
			}
		}
		printf("%s\n", ans?"FAKE":"OK");
	}
	return 0;
}

