// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 05월 13일 18시 14분 31초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int n;
int arr[100000];
int main(){
	scanf("%d%d%d", &a, &b, &c);
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	sort(arr, arr+n);
	int ans=0;
	for(int i=0;i<n;i++){
		if(arr[i]>b&&arr[i]<c){
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}

