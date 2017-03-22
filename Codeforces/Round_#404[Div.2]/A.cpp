// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 03월 21일 19시 38분 45초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
char input[100];
int main(){
	scanf("%d", &n);
	int ans=0;
	for(int i=0;i<n;i++){
		scanf("%s", input);
		if(input[0]=='T')
			ans+=4;
		if(input[0]=='C')
			ans+=6;
		if(input[0]=='O')
			ans+=8;
		if(input[0]=='D')
			ans+=12;
		if(input[0]=='I')
			ans+=20;
	}
	printf("%d\n", ans);
	return 0;
}

