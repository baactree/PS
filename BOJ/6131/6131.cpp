// =====================================================================================
// 
//       Filename:  6131.cpp
//        Created:  2017년 01월 15일 18시 20분 22초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	int ans=0;
	for(int i=1;i<=500;i++)
		for(int j=i;j<=500;j++)
			if(j*j-i*i==N)
				ans++;
	printf("%d\n", ans);
	return 0;
}

