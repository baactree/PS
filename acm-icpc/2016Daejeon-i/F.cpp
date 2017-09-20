// =====================================================================================
// 
//       Filename:  F.cpp
//        Created:  2017년 09월 16일 19시 44분 27초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int dp[10001];
bool possi[10001][10001];
int n, k, l;
char str[10005];
int main(){
	scanf("%d%d%d", &n, &k, &l);	
	scanf("%s", str+1);
	memset(dp, 0x3f, sizeof(dp));
	dp[0]=0;
	for(int i=1;i<n;i++){
		int le, ri, len;
		le=i;
		ri=i+1;
		len=0;
		while(le>=1&&ri<=n){
			if(str[le]==str[ri])
				len++;
			else
				len=0;
			if((ri-le+1)*k<=2*len*l)
				possi[ri][le]=true;
			le--;
			ri++;
		}
		le=i;
		ri=i+2;
		len=0;
		while(le>=1&&ri<=n){
			if(str[le]==str[ri])
				len++;
			else
				len=0;
			if((ri-le+1)*k<=2*len*l)
				possi[ri][le]=true;
			le--;
			ri++;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			if(possi[i][j])
				dp[i]=min(dp[i], dp[j-1]+1);
	printf("%d\n", dp[n]==0x3f3f3f3f?0:dp[n]);
	return 0;
}

