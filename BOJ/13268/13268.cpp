// =====================================================================================
// 
//       Filename:  13268.cpp
//        Created:  2017년 09월 13일 22시 08분 35초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int col[21];
int main(){
	int n;
	scanf("%d", &n);
	for(int i=1;i<=5;i++)
		col[i]=1;
	for(int i=6;i<=10;i++)
		col[i]=2;
	for(int i=11;i<=15;i++)
		col[i]=3;
	for(int i=16;i<=20;i++)
		col[i]=4;
	n%=100;
	int loc=0;
	int dir=1;
	for(int cnt=0;cnt<n;cnt++){
		loc=loc+dir;
		if(loc==0||cnt+1==5||cnt+1==20||cnt+1==45||cnt+1==80)
			dir=-dir;
	}
	printf("%d\n", col[loc]);
	return 0;
}

