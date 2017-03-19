// =====================================================================================
// 
//       Filename:  6376.cpp
//        Created:  2017년 03월 19일 21시 46분 40초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
double f[10];
int main(){
	printf("n e\n");
	f[0]=1;
	for(int i=1;i<10;i++)
		f[i]=f[i-1]*i;
	printf("- -----------\n");
	double e=0;
	for(int i=0;i<10;i++){
		e+=1./f[i];
		if(i<3)
			printf("%d %g\n", i, e);
		else
			printf("%d %.9lf\n",i, e);
	}
	return 0;
}

