// =====================================================================================
// 
//       Filename:  1415.cpp
//        Created:  2017년 05월 29일 21시 06분 15초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
bool prime[500005];
int n;
int check[10005];
vector<pair<int, int> > arr;
long long dp[2][500005];
int main(){
	prime[0]=prime[1]=true;
	for(int i=2;i<500005;i++)
		if(!prime[i]){
			for(int j=i+i;j<500005;j+=i)
				prime[j]=true;
		}
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int in;
		scanf("%d", &in);
		check[in]++;
	}
	for(int i=0;i<10005;i++)
		if(check[i]>0)
			arr.push_back({i, check[i]});
	dp[0][0]=1;
	for(int i=0;i<arr.size();i++){
		int now=i&1;
		int next=(i+1)&1;
		for(int j=0;j<500005;j++)
			dp[next][j]=0;
		for(int j=0;j<500005;j++){
			for(int k=0;k<=arr[i].second;k++)
				if(arr[i].first*k+j<500005)
					dp[next][j+arr[i].first*k]+=dp[now][j];
		}
	}
	long long ans=0;
	for(int i=0;i<500005;i++)
		if(!prime[i])
			ans+=dp[arr.size()&1][i];
	printf("%lld\n", ans);
	return 0;
}

