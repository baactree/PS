// =====================================================================================
// 
//       Filename:  11508.cpp
//        Created:  2017년 05월 05일 11시 00분 13초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100000];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	sort(arr, arr+n);
	int ans=0;
	for(int i=n-1;i>=0;i--){
		if(i-2>=0){
			ans+=arr[i];
			ans+=arr[i-1];
			i-=2;
		}
		else
			ans+=arr[i];
	}
	printf("%d\n", ans);
	return 0;
}

