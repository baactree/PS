// =====================================================================================
// 
//       Filename:  13137.cpp
//        Created:  2017년 06월 07일 16시 50분 42초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100];
int g[200005];
int dp[200005];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	for(int i=1;i<200005;i++){
		int idx=upper_bound(arr, arr+n, i)-arr-1;
		g[i]=g[i-arr[idx]]+1;
		int val=0x3f3f3f3f;
		for(int j=0;j<n;j++){
			if(i-arr[j]>=0){
				val=min(val, dp[i-arr[j]]+1);	
			}
		}
		dp[i]=val;
	}
	bool flag=false;
	for(int i=0;i<200005;i++)
		if(dp[i]!=g[i])
			flag=true;
	printf("%s\n", flag?"No":"Yes");
	return 0;
}

