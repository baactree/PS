// =====================================================================================
// 
//       Filename:  13422.cpp
//        Created:  2017년 04월 25일 00시 28분 43초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int arr[200005];
long long sum[200005];
int n;
int m;
long long k;
int main(){
	int TestCase;
	scanf("%d", &TestCase);
	while(TestCase--){
		scanf("%d%d%lld", &n, &m, &k);
		for(int i=1;i<=n;i++){
			scanf("%d", &arr[i]);
			arr[i+n]=arr[i];
		}
		for(int i=1;i<=n*2;i++)
			sum[i]=sum[i-1]+arr[i];
		if(n==m){
			printf("%d\n", sum[n]<k);
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			if(sum[i+m-1]-sum[i-1]<k)
				ans++;
		printf("%d\n", ans);
	}
	return 0;
}

