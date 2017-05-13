// =====================================================================================
// 
//       Filename:  4690.cpp
//        Created:  2017년 05월 13일 22시 22분 33초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	for(int a=2;a<=100;a++)
		for(int b=2;b<=100;b++)
			for(int c=b;c<=100;c++)
				for(int d=c;d<=100;d++){
					if(a*a*a==b*b*b+c*c*c+d*d*d){
						printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
					}
				}
	return 0;
}

