// =====================================================================================
// 
//       Filename:  13140.cpp
//        Created:  2017년 04월 07일 20시 33분 51초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int a[10];
// d e h l o r w
// 0 1 2 3 4 5 6
//
// 2 1 3 3 4
// 6 4 5 3 0
int main(){
	for(int i=0;i<10;i++)
		a[i]=i;
	scanf("%d", &n);
	do{
		if(a[2]==0||a[6]==0)
			continue;
		if(a[0]+a[4]+10*(2*a[3])+100*(a[3]+a[5])+1000*(a[1]+a[4])+10000*(a[2]+a[6])==n){
			printf("  %d%d%d%d%d\n+ %d%d%d%d%d\n-------\n%7d\n", a[2], a[1], a[3], a[3], a[4], a[6], a[4], a[5], a[3], a[0], n);
			return 0;
		}
	}while(next_permutation(a, a+10));
	printf("No Answer\n");
	return 0;
}

