// =====================================================================================
// 
//       Filename:  13701.cpp
//        Created:  2017년 04월 29일 13시 04분 37초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <stdio.h>

int check[1<<20];
int main(){
	int in;
	while(scanf("%d", &in)!=EOF){
		if(!(check[in>>5]&(1<<(in&((1<<5)-1))))){
			printf("%d ", in);
			check[in>>5]|=(1<<(in&((1<<5)-1)));
		}
	}
	return 0;
}

