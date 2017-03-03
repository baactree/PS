// =====================================================================================
// 
//       Filename:  3076.cpp
//        Created:  2017년 03월 01일 20시 15분 44초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int r, c, a, b;
int main(){
	scanf("%d%d%d%d", &r, &c, &a, &b);
	for(int i=0;i<r;i++)
		for(int j=0;j<a;j++){
			for(int k=0;k<c;k++){
				for(int t=0;t<b;t++){
					printf("%c", (i+k)&1?'.':'X');
				}
			}
			printf("\n");
		}
	return 0;
}

