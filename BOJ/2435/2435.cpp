// =====================================================================================
// 
//       Filename:  2435.cpp
//        Created:  2017년 03월 01일 20시 09분 24초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[100];
int main(){
	scanf("%d%d", &n, &k);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	int ans=-0x3f3f3f3f;
	for(int i=0;i<=n-k;i++){
		int sum=0;
		for(int j=0;j<k;j++)
			sum+=arr[i+j];
		ans=max(ans, sum);
	}
	printf("%d\n", ans);
	return 0;
}

