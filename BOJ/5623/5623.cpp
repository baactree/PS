
// =====================================================================================
// 
//       Filename:  5623.cpp
//        Created:  2017년 04월 02일 01시 58분 49초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
long long n;
long long mat[1000][1000];
int main(){
	scanf("%lld", &n);
	long long sum=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			scanf("%lld", &mat[i][j]);
			if(j<i)
				sum+=mat[i][j];
		}
	if(n==2){
		printf("1 %lld\n", mat[0][1]-1);
		return 0;
	}
	sum/=n-1;
	for(int i=1;i<n;i++)
		sum-=mat[0][i];
	sum=(-sum)/(n-2);
	printf("%lld", sum);
	for(int i=1;i<n;i++)
		printf(" %lld", mat[0][i]-sum);
	return 0;
}

