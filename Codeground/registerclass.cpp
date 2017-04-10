// =====================================================================================
// 
//       Filename:  registerclass.cpp
//        Created:  2017년 04월 10일 19시 45분 42초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int main(){
	int TestCase;
	scanf("%d", &TestCase);
	for(int tc=1;tc<=TestCase;tc++){
		int n, m;
		scanf("%d%d", &n, &m);
		vector<int> arr(n);
		for(int i=0;i<n;i++)
			scanf("%d", &arr[i]);
		vector<int> dp(m+1, 0);
		for(int i=0;i<n;i++)
			for(int j=m-arr[i];j>=0;j--){
				dp[j+arr[i]]=max(dp[j+arr[i]], dp[j]+arr[i]);
			}
		printf("Case #%d\n%d\n", tc, dp[m]);
	}
	return 0;
}

