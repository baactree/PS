// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 03월 09일 15시 36분 59초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>'a'+cnt){
			printf("NO\n");
			return 0;
		}
		if(s[i]=='a'+cnt)
			cnt++;
	}
	printf("YES\n");
	return 0;
}
