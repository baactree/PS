// =====================================================================================
// 
//       Filename:  2548.cpp
//        Created:  2017년 03월 15일 21시 33분 46초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[20000];
int sum;
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
		sum+=arr[i];
	}
	int ans;
	int min_value=2*1e9;
	for(int i=0;i<n;i++){
		int now=0;
		for(int j=0;j<n;j++)
			now+=abs(arr[i]-arr[j]);
		if(min_value>now){
			min_value=now;
			ans=arr[i];
		}
		else if(min_value==now){
			ans=min(ans, arr[i]);
		}
	}
	printf("%d\n", ans);
	return 0;
}

