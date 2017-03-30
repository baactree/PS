// =====================================================================================
// 
//       Filename:  13909.cpp
//        Created:  2017년 03월 31일 02시 36분 02초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d", &n);
	int cnt=0;
	for(int i=1;i*i<=n;i++)
		cnt++;
	printf("%d\n", cnt);
	return 0;
}

