// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 06월 10일 21시 01분 25초
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
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	sort(arr, arr+n);
	printf("%d\n", arr[n-1]-arr[0]);
	return 0;
}

