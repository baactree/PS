// =====================================================================================
// 
//       Filename:  10262.cpp
//        Created:  2017년 09월 20일 20시 45분 16초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	double arr[2];
	for(int i=0;i<2;i++){
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		arr[i]=(b*(b+1)/2.-a*(a-1)/2)/(b-a+1)+(d*(d+1)/2.-c*(c-1)/2)/(d-c+1);
	}
	if(arr[0]<arr[1])
		printf("Emma\n");
	else if(arr[0]>arr[1])
		printf("Gunnar\n");
	else
		printf("Tie\n");
	return 0;
}

