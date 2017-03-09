// =====================================================================================
// 
//       Filename:  4706.cpp
//        Created:  2017년 03월 09일 20시 09분 02초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
double ta, tb;
int main(){
	while(true){
		scanf("%lf%lf", &ta, &tb);
		if(ta==0&&tb==0)
			break;
		printf("%.3lf\n", sqrt(1-pow(tb/ta, 2)));
	}
	return 0;
}

