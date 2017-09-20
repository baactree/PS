// =====================================================================================
// 
//       Filename:  1248.cpp
//        Created:  2017년 09월 19일 00시 47분 26초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int pick[15];
char mat[15][15];
int sum[15][15];
void solve(int idx){
	if(idx==n+1){
		for(int i=1;i<=n;i++)
			printf("%d ", pick[i]);
		exit(0);
	}
	for(int i=-10;i<=10;i++){
		for(int j=0;j<=idx;j++){
			sum[j][idx]=sum[j][idx-1]+i;
		}
		bool flag=false;
		for(int j=1;j<=idx;j++){
			if(mat[j][idx]=='+'){
				if(sum[j][idx]<=0)
					flag=true;
			}
			else if(mat[j][idx]=='-'){
				if(sum[j][idx]>=0)
					flag=true;
			}
			else{
				if(sum[j][idx]!=0)
					flag=true;
			}
		}
		if(!flag){
			pick[idx]=i;
			solve(idx+1);
		}
	}
}
int main(){
	scanf("%d", &n);
	string str;
	cin>>str;
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++)
			mat[i+1][j+1]=str[cnt++];
	}
	solve(1);
	return 0;
}

