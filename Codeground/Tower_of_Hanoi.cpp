// =====================================================================================
// 
//       Filename:  Tower_of_Hanoi.cpp
//        Created:  2017년 06월 29일 22시 42분 09초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
void solve(int s, int t, int d, int n){
	if(n==1){
		printf("%d -> %d\n", s, t);
		return;
	}
	solve(s, d, t, n-1);
	printf("%d -> %d\n", s, t);
	solve(d, t, s, n-1);
}
int main(){
	int testcase;
	scanf("%d", &testcase);
	for(int tc=1;tc<=testcase;tc++){
		int n;
		scanf("%d", &n);
		printf("Case #%d\n", tc);
		solve(1, 3, 2, n);
	}
	return 0;
}

