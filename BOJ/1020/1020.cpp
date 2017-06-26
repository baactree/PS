// =====================================================================================
// 
//       Filename:  1020.cpp
//        Created:  2017년 06월 26일 19시 19분 38초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string str;
int arr[10]={6, 2, 5, 5, 4, 5, 6, 3, 7, 5};
int n;
long long dp[16][1000][2];
long long int mod;
int main(){
	cin>>str;
	n=str.size();
	mod=1;
	for(int i=0;i<n;i++)
		mod*=10;
	for(int i=0;i<16;i++)
		for(int j=0;j<1000;j++)
			for(int k=0;k<2;k++)
				dp[i][j][k]=mod;
	long long p=10;
	dp[0][500][0]=0;
	for(int i=0;i<n;i++, p*=10)
		for(int j=0;j<1000;j++){
			for(int k=0;k<2;k++){
				if(dp[i][j][k]==mod)
					continue;
				for(int q=0;q<10;q++){
					int next=k;
					if(q>str[i]-'0')
						next=1;
					int diff=arr[q]-arr[str[i]-'0'];
					long long t=(q-(str[i]-'0'))*(mod/p);
					if(k==0&&t<0){
						t=(t+mod)%mod;
						next=1;
					}
					if(j+diff>=0&&j+diff<1000){
						dp[i+1][j+diff][next]=min(dp[i+1][j+diff][next], dp[i][j][k]+t);
					//	printf("%d %d %d %d -> %d %d %d %d\n", i, j, k, q, i+1, j+diff, next, t);
					}
				}
			}
		}
	printf("%lld\n", dp[n][500][1]);
	return 0;
}

