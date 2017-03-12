// =====================================================================================
// 
//       Filename:  5692.cpp
//        Created:  2017년 03월 12일 17시 58분 41초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int f[6];
int main(){
	f[0]=1;
	for(int i=1;i<6;i++)
		f[i]=f[i-1]*i;
	while(true){
		char input[10];
		string n;
		scanf("%s", input);
		n=input;
		if(n=="0")
			break;
		int ans=0;
		for(int i=0;i<n.size();i++)
			ans+=(n[i]-'0')*f[n.size()-i];
		printf("%d\n", ans);
	}
	return 0;
}

