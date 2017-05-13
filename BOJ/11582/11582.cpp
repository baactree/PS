// =====================================================================================
// 
//       Filename:  11582.cpp
//        Created:  2017년 05월 12일 12시 41분 20초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[1<<20];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	scanf("%d", &k);
	for(int i=0;i<n;i+=n/k)
		sort(arr+i, arr+i+n/k);
	for(int i=0;i<n;i++)
		printf("%d%c", arr[i], " \n"[i==n-1]);
	return 0;
}

