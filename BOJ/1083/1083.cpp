// =====================================================================================
// 
//       Filename:  1083.cpp
//        Created:  2017년 08월 01일 16시 07분 43초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, s;
int arr[50];
int main(){
	while(scanf("%d", &n)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%d", &arr[i]);
		scanf("%d", &s);
		for(int i=0;i<n;i++){
			int max_value=-1;
			int idx=-1;
			for(int j=i+1;j<n;j++){
				if(arr[i]<arr[j]&&j-i<=s&&max_value<arr[j]){
					max_value=arr[j];
					idx=j;
				}
			}
			if(idx!=-1){
				for(int j=idx;j>i;j--){
					swap(arr[j], arr[j-1]);
					s--;
				}
			}
		}
		for(int i=0;i<n;i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
	return 0;
}

