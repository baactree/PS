// =====================================================================================
// 
//       Filename:  14517.cpp
//        Created:  2017년 08월 06일 00시 11분 42초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int tree[1005][1005];
const int mod=(1<<30)+5;
void update(int idx, int val, int row){
	idx++;
	while(idx<1005){
		tree[row][idx]=(tree[row][idx]+val)%mod;
		idx+=idx&(-idx);
	}
}
int query(int idx, int row){
	int ret=0;
	idx++;
	while(idx){
		ret=(ret+tree[row][idx])%mod;
		idx-=idx&(-idx);
	}
	return ret;
}
int main(){
	string str;
	cin>>str;
	for(int i=0;i<str.size();i++){
		int sum=0;
		for(int j=i;j>=0;j--){
			if(j+1<i)
				sum=(sum+query(i-1, j+1)-query(j, j+1)+mod)%mod;
			if(str[j]==str[i]){
				dp[j][i]=(dp[j][i]+sum+1)%mod;
				update(i, sum+1, j);
			}
		}
	}
	int ans=0;
	for(int i=0;i<str.size();i++)
		for(int j=i;j<str.size();j++){
			ans=(ans+dp[i][j])%mod;
		}
	cout<<ans<<endl;
	return 0;
}
