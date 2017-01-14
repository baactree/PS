// =====================================================================================
// 
//       Filename:  2847.cpp
//        Created:  2017년 01월 14일 20시 00분 20초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int N;
int arr[100];
int main(){
	scanf("%d", &N);
	for(int i=0;i<N;i++)
		scanf("%d", &arr[i]);
	int ans=0;
	for(int i=N-2;i>=0;i--){
		ans+=max(0, arr[i]-arr[i+1]+1);
		arr[i]=min(arr[i], arr[i+1]-1);
	}
	printf("%d\n", ans);
	return 0;
}

