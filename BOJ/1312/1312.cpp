// =====================================================================================
// 
//       Filename:  1312.cpp
//        Created:  2017년 03월 12일 18시 22분 08초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b, n;
	int ans;
	scanf("%d%d%d", &a, &b, &n);
	for(int i=0;i<n;i++){
		ans=(a*10/b)%10;
		a=(a*10)%b;
	}
	printf("%d\n", ans);
	return 0;
}

