// =====================================================================================
// 
//       Filename:  14487.cpp
//        Created:  2017년 04월 24일 11시 21분 39초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[50000];
int main(){
	scanf("%d", &n);
	int sum=0;
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
		sum+=arr[i];
	}
	printf("%d\n", sum-*max_element(arr, arr+n));
	return 0;
}

