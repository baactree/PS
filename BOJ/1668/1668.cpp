// =====================================================================================
// 
//       Filename:  1668.cpp
//        Created:  2017년 03월 22일 14시 14분 07초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[50];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	int now=0;
	int lcnt=0;
	for(int i=0;i<n;i++){
		if(now<arr[i]){
			lcnt++;
			now=arr[i];
		}
	}
	now=0;
	int rcnt=0;
	for(int i=n-1;i>=0;i--){
		if(now<arr[i]){
			rcnt++;
			now=arr[i];
		}
	}
	printf("%d\n%d\n", lcnt, rcnt);
	return 0;
}

