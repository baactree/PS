// =====================================================================================
// 
//       Filename:  13118.cpp
//        Created:  2017년 04월 07일 17시 20분 46초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int x[4];
int a, b, c;
int main(){
	for(int i=0;i<4;i++)
		scanf("%d", &x[i]);
	scanf("%d%d%d", &a, &b, &c);
	for(int i=0;i<4;i++){
		if(x[i]==a){
			printf("%d\n", i+1);
			return 0;
		}
	}
	printf("0\n");
	return 0;
}

