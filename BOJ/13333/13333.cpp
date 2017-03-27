// =====================================================================================
// 
//       Filename:  13333.cpp
//        Created:  2017년 03월 27일 22시 39분 29초
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
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	for(int i=0;i<=10000;i++){
		int cnt=0;
		int cnt2=0;
		for(int j=0;j<n;j++){
			if(arr[j]>=i)
				cnt++;
			if(arr[j]<=i)
				cnt2++;
		}
		if(cnt==i){
			printf("%d\n", cnt);
			return 0;
		}
		if(cnt2==n-i){
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}

