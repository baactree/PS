// =====================================================================================
// 
//       Filename:  5671.cpp
//        Created:  2017년 04월 13일 19시 10분 22초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
bool possi(int x){
	string s=to_string(x);
	sort(s.begin(), s.end());
	for(int i=1;i<s.size();i++){
		if(s[i]==s[i-1])
			return false;
	}
	return true;
}
int main(){
	while(scanf("%d%d", &n, &m)!=EOF){
		int ans=0;
		for(int i=n;i<=m;i++){
			if(possi(i))
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}

