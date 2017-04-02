// =====================================================================================
// 
//       Filename:  12782.cpp
//        Created:  2017년 04월 01일 20시 16분 29초
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
		string a, b;
		cin>>a>>b;
		int acnt, bcnt;
		acnt=bcnt=0;
		int cnt=0;
		for(int i=0;i<a.size();i++){
			if(a[i]!=b[i])
				cnt++;
			if(a[i]=='0')
				acnt++;
			if(b[i]=='0')
				bcnt++;
		}
		int ans=abs(acnt-bcnt);
		ans=(cnt-ans)/2+ans;
		printf("%d\n", ans);
	}
	return 0;
}

