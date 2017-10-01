// =====================================================================================
// 
//       Filename:  8902.cpp
//        Created:  2017년 10월 01일 17시 48분 32초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string a,b;
int dp[5005][5005];
int sa[26],sb[26],ea[26],eb[26];
const int inf=0x3f3f3f3f;
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		cin>>a>>b;
		memset(sa,0x3f,sizeof(sa));
		memset(sb,0x3f,sizeof(sb));
		memset(ea,-1,sizeof(ea));
		memset(eb,-1,sizeof(eb));
		for(int i=0;i<a.size();i++){
			int now=a[i]-'A';
			if(sa[now]==inf)
				sa[now]=i;
			ea[now]=i;
		}
		for(int i=0;i<b.size();i++){
			int now=b[i]-'A';
			if(sb[now]==inf)
				sb[now]=i;
			eb[now]=i;
		}
		memset(dp,0x3f,sizeof(dp));
		dp[0][0]=0;
		for(int i=0;i<=a.size();i++)
			for(int j=0;j<=b.size();j++){
				if(i<a.size()){
					int now=a[i]-'A';
					int temp=0;
					if(sa[now]==i&&j<=sb[now])
						temp-=i+j;
					if(ea[now]==i&&j>eb[now])
						temp+=i+j;
					dp[i+1][j]=min(dp[i+1][j],dp[i][j]+temp);
				}
				if(j<b.size()){
					int now=b[j]-'A';
					int temp=0;
					if(sb[now]==j&&i<=sa[now])
						temp-=i+j;
					if(eb[now]==j&&i>ea[now])
						temp+=i+j;
					dp[i][j+1]=min(dp[i][j+1],dp[i][j]+temp);
				}
			}
		printf("%d\n",dp[a.size()][b.size()]);
	}
	return 0;
}