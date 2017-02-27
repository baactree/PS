// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 02월 25일 22시 06분 36초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
bool isprime(int x){
	if(x==2)
		return true;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return false;
	return true;
}
int main(){
	scanf("%d", &n);
	if(n<=2){
		printf("1\n");
		for(int i=0;i<n;i++)
			printf("1 ");
		printf("\n");
		return 0;
	}
	int color=1;
	vector<int> ans;
	printf("2\n");
	for(int i=2;i<n+2;i++){
		if(!isprime(i))
			printf("2 ");
		else 
			printf("1 ");
	}
	printf("\n");
	return 0;
}

