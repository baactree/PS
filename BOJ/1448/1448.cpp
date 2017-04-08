// =====================================================================================
// 
//       Filename:  1448.cpp
//        Created:  2017년 04월 07일 16시 04분 54초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1000000];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	sort(arr, arr+n);
	if(arr[n-1]>=arr[n-2]+arr[n-3])
		printf("-1\n");
	else
		printf("%d\n", arr[n-1]+arr[n-2]+arr[n-3]);
	return 0;
}

