// =====================================================================================
// 
//       Filename:  14720.cpp
//        Created:  2017년 09월 19일 22시 05분 46초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int ans=0;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d", &x);
		if(ans%3==x)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}

