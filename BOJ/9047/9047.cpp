// =====================================================================================
// 
//       Filename:  9047.cpp
//        Created:  2017년 02월 21일 15시 49분 06초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int Case;
	scanf("%d", &Case);
	while(Case--){
		int a;
		scanf("%d", &a);
		int ans=0;
		while(a!=6174){
			string l, s;
			s=to_string(a);
			string t="";
			for(int i=0;i<4-s.size();i++)
				t+="0";
			s=t+s;
			sort(s.begin(), s.end());
			l=s;
			reverse(l.begin(), l.end());
			ans++;
			a=stoi(l)-stoi(s);
		}
		printf("%d\n", ans);
	}
	return 0;
}

