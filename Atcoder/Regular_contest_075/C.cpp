// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 06월 03일 21시 01분 19초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100];
int main(){
	scanf("%d", &n);
	int sum=0;
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
		sum+=arr[i];
	}
	if(sum%10!=0){
		printf("%d\n", sum);
		return 0;
	}
	else{
		sort(arr, arr+n);
		for(int i=0;i<n;i++){
			if(arr[i]%10!=0){
				printf("%d\n", sum-arr[i]);
				return 0;
			}
		}
	}
	printf("0\n");
	return 0;
}

