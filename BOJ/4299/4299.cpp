// =====================================================================================
// 
//       Filename:  4299.cpp
//        Created:  2017년 02월 20일 19시 06분 13초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	for(int i=0;i<=1000;i++)
		for(int j=0;j<=i;j++){
			if(i+j==a&&i-j==b){
				printf("%d %d\n", i, j);
				return 0;
			}
		}
	printf("-1\n");
	return 0;
}

