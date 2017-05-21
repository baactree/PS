// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 05월 21일 20시 39분 28초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int arr[100];
int n, k;
int main(){
	scanf("%d%d", &n, &k);
	int sum=0;
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
		sum+=arr[i];
	}
	int cnt=0;
	while(true){
		if((sum+cnt*k)*10>=(k*10-5)*(cnt+n)){
			printf("%d\n", cnt);
			return 0;
		}
		cnt++;
	}
	return 0;
}

