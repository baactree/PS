// =====================================================================================
// 
//       Filename:  14563.cpp
//        Created:  2017년 08월 10일 00시 42분 12초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		int n;
		scanf("%d", &n);
		int sum=n!=1;
		for(int i=2;i*i<=n;i++){
			if(n%i==0){
				sum+=i;
				if(i*i!=n)
					sum+=n/i;
			}
		}
		if(sum>n)
			printf("Abundant\n");
		else if(sum<n)
			printf("Deficient\n");
		else
			printf("Perfect\n");
	}
	return 0;
}

