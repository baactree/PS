// =====================================================================================
// 
//       Filename:  E.cpp
//        Created:  2017년 04월 27일 19시 12분 34초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, p, k;
int A[1005];
int B[1005];
int dp[2][1005][55][55];
int main(){
	scanf("%d%d%d", &n, &p, &k);
	int c;
	scanf("%d", &c);
	for(int i=0;i<c;i++){
		int in;
		scanf("%d", &in);
		A[in]=1;
	}
	scanf("%d", &c);
	for(int i=0;i<c;i++){
		int in;
		scanf("%d", &in);
		B[in]=1;
	}
	p=min(p, 2*((n+k-1)/k));
	memset(dp, -1, sizeof(dp));
	dp[1][0][0][0]=0;
	for(int i=1;i<=n;i++){
		int now=i&1;
		int next=(i+1)&1;
		for(int j=0;j<=p;j++)
			for(int a=0;a<k;a++)
				for(int b=0;b<k;b++)
					dp[next][j][a][b]=-1;
		for(int j=0;j<=p;j++)
			for(int a=0;a<k;a++)
				for(int b=0;b<k;b++){
					if(dp[now][j][a][b]==-1)
						continue;
					//a만 보는 경우
					if(j+1<=p){
						int na=1;
						int nb=b+1;
						if(na==k)
							na=0;
						if(nb==1||nb==k)
							nb=0;
						dp[next][j+1][na][nb]=max(dp[next][j+1][na][nb],
								dp[now][j][a][b]+(b==0?A[i]:(A[i]||B[i])));
					}
					//b만 보는 경우
					if(j+1<=p){
						int na=a+1;
						int nb=1;
						if(na==1||na==k)
							na=0;
						if(nb==k)
							nb=0;
						dp[next][j+1][na][nb]=max(dp[next][j+1][na][nb], 
								dp[now][j][a][b]+(a==0?B[i]:(A[i]||B[i])));
					}
					//a, b둘 다 보는경우
					if(j+2<=p){
						int na=1;
						int nb=1;
						if(na==k)
							na=0;
						if(nb==k)
							nb=0;
						dp[next][j+2][na][nb]=max(dp[next][j+2][na][nb], dp[now][j][a][b]+(A[i]||B[i]));
					}
					//둘 다 안 보는 경우
					int na=a+1;
					int nb=b+1;
					if(na==1||na==k)
						na=0;
					if(nb==1||nb==k)
						nb=0;
					int sum=0;
					if(a==0&&b==0)
						sum=0;
					else if(a==0)
						sum=B[i];
					else if(b==0)
						sum=A[i];
					else
						sum=A[i]||B[i];
					dp[next][j][na][nb]=max(dp[next][j][na][nb], dp[now][j][a][b]+sum);
				}
	}
	int ans=0;
	for(int i=0;i<k;i++)
		for(int j=0;j<k;j++)
			ans=max(ans, dp[(n+1)&1][p][i][j]);
	printf("%d\n", ans);
	return 0;
}
