// =====================================================================================
// 
//       Filename:  10453.cpp
//        Created:  2017년 03월 04일 20시 59분 10초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string a, b;
int cnt[26];
int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		memset(cnt, 0, sizeof(cnt));
		cin>>a>>b;
		int idx=0;
		long long ans=0;
		if(a.size()!=b.size()){
			printf("-1\n");
			goto go;
		}
		for(int i=0;i<a.size();i++)
			cnt[a[i]-'a']++;
		for(int i=0;i<b.size();i++)
			cnt[b[i]-'a']--;
		for(int i=0;i<26;i++)
			if(cnt[i]!=0)
				goto go;
		for(int i=0;i<a.size();i++){
			if(a[i]=='a')
				continue;
			while(b[idx]=='a')
				idx++;
			ans+=abs(idx-i);
			idx++;
		}
		printf("%lld\n", ans);

		go:;
	}
	return 0;
}

