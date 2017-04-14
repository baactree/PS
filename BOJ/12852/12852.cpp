// =====================================================================================
// 
//       Filename:  12852.cpp
//        Created:  2017년 04월 14일 10시 55분 44초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int dp[1000005];
int main(){
	scanf("%d", &n);
	memset(dp, 0x3f, sizeof(dp));
	dp[1]=0;
	for(int i=2;i<=n;i++){
		if(i%3==0)
			dp[i]=min(dp[i], dp[i/3]+1);
		if(i%2==0)
			dp[i]=min(dp[i], dp[i/2]+1);
		dp[i]=min(dp[i], dp[i-1]+1);
	}
	printf("%d\n", dp[n]);
	vector<int> ans;
	while(true){
		ans.push_back(n);
		if(n==1)
			break;
		int a, b, c;
		a=b=c=0x3f3f3f3f;
		if(n%3==0)
			a=dp[n/3]+1;
		if(n%2==0)
			b=dp[n/2]+1;
		c=dp[n-1]+1;
		if(a<=min(b, c))
			n/=3;
		else if(b<=min(a, c))
			n/=2;
		else
			n-=1;
	}
	for(int i=0;i<ans.size();i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}

