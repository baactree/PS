// =====================================================================================
// 
//       Filename:  14505.cpp
//        Created:  2017년 08월 07일 12시 53분 56초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int dp[40][40];
int main(){
	string str;
	cin>>str;
	for(int i=0;i<str.size();i++){
		for(int j=0;j<=i;j++){
			if(str[j]==str[i]){
				dp[j][i]++;
				int sum=0;
				for(int x=j+1;x<i;x++)
					for(int y=x;y<i;y++)
						sum+=dp[x][y];
				dp[j][i]+=sum;
			}
		}
	}
	int ans=0;
	for(int i=0;i<str.size();i++)
		for(int j=i;j<str.size();j++)
			ans+=dp[i][j];
	cout<<ans<<endl;
	return 0;
}

