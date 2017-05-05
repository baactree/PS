// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 05월 04일 23시 53분 28초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main(){
	scanf("%d", &n);
	if(n<=2){
		for(int i=0;i<n;i++)
			printf("a");
		printf("\n");
		return 0;
	}
	string ans="aa";
	for(int i=2;i<n;i++){
		if(ans[i-2]=='a')
			ans+='b';
		else
			ans+='a';
	}
	cout<<ans<<endl;
	return 0;
}

