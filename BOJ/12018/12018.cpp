// =====================================================================================
// 
//       Filename:  12018.cpp
//        Created:  2017년 04월 23일 17시 07분 18초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[100];
int temp[100];
int dp[105];
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++){
		int p, l;
		scanf("%d%d", &p, &l);
		for(int j=0;j<p;j++)
			scanf("%d", &temp[j]);
		sort(temp, temp+p);
		if(p<l)
			arr[i]=1;
		else
			arr[i]=temp[p-l];
	}
	for(int i=0;i<n;i++)
		for(int j=m-arr[i];j>=0;j--){
			dp[j+arr[i]]=max(dp[j+arr[i]], dp[j]+1);
		}
	printf("%d\n", dp[m]);
	return 0;
}

