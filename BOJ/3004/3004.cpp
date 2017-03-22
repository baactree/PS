// =====================================================================================
// 
//       Filename:  3004.cpp
//        Created:  2017년 03월 22일 14시 08분 56초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int cnt=0;
	int ans=0;
	for(int i=0;i<=n;i++){
		if(i%2==0)
			cnt++;
		ans+=cnt;
	}
	printf("%d\n", ans);
	return 0;
}

