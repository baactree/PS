// =====================================================================================
// 
//       Filename:  3061.cpp
//        Created:  2017년 05월 22일 16시 35분 55초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1000];
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		scanf("%d", &n);
		for(int i=0;i<n;i++)
			scanf("%d", &arr[i]);
		int ans=0;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(arr[i]>arr[j]){
					swap(arr[i], arr[j]);
					ans++;
				}
		printf("%d\n", ans);
	}
	return 0;
}

