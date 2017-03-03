// =====================================================================================
// 
//       Filename:  1145.cpp
//        Created:  2017년 02월 04일 21시 03분 24초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int arr[5];
int gcd(int a, int b){
	return b?gcd(b, a%b):a;
}
int main(){
	for(int i=0;i<5;i++)
		scanf("%d", &arr[i]);
	int ans=0x3f3f3f3f;
	for(int i=0;i<5;i++)
		for(int j=i+1;j<5;j++)
			for(int k=j+1;k<5;k++){
				int tt=gcd(arr[i], arr[j]);
				int now=arr[i]/tt*arr[j];
				tt=gcd(now, arr[k]);
				now=now/tt*arr[k];
				ans=min(ans, now);
			}
	printf("%d\n", ans);
	return 0;
}

