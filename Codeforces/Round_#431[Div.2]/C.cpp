// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 09월 15일 22시 59분 37초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

vector<int> vec;
int dp[100005];
int par[100005];
int main(){
	for(int i=1;i*(i+1)/2<=1e5;i++)
		vec.push_back(i*(i+1)/2);
	int k;
	scanf("%d", &k);
	if(k==0)
		return !printf("a\n");
	memset(dp, 0x3f, sizeof(dp));
	dp[0]=0;
	for(int i=0;i<=k;i++){
		int idx=-1;
		for(int j=0;j<vec.size();j++){
			if(i-vec[j]>=0){
				if(dp[i]>dp[i-vec[j]]+1){
					dp[i]=dp[i-vec[j]]+1;
					idx=j;
				}
			}
		}
		par[i]=idx;
	}
	vector<int> ans;
	int now=k;
	while(now){
		ans.push_back(par[now]);
		now=now-vec[par[now]];
	}
	int cnt=0;
	string str="";
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i]+2;j++)
			str+=(char)('a'+cnt);
		cnt++;
	}
	cout<<str<<endl;
	return 0;
}

