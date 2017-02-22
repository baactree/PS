// =====================================================================================
// 
//       Filename:  2780.cpp
//        Created:  2017년 02월 22일 15시 48분 53초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int mat[10][10];
int cache[1000][10];
const int mod = 1234567;
int n;
int solve(int idx, int now){
	if(idx==n){
		return 1;
	}
	int &ret=cache[idx][now];
	if(ret!=-1)
		return ret;
	ret=0;
	for(int i=0;i<10;i++)
		if(mat[now][i]){
			ret+=solve(idx+1, i);
			ret%=mod;
		}
	return ret;
}
int main(){
	mat[0][7]=true;
	mat[1][2]=mat[1][4]=true;
	mat[2][1]=mat[2][5]=mat[2][3]=true;
	mat[3][2]=mat[3][6]=true;
	mat[4][1]=mat[4][5]=mat[4][7]=true;
	mat[5][4]=mat[5][2]=mat[5][6]=mat[5][8]=true;
	mat[6][3]=mat[6][5]=mat[6][9]=true;
	mat[7][4]=mat[7][8]=mat[7][0]=true;
	mat[8][5]=mat[8][7]=mat[8][9]=true;
	mat[9][6]=mat[9][8]=true;
	int Case;
	cin>>Case;
	while(Case--){
		scanf("%d", &n);
		memset(cache, -1, sizeof(cache));
		int ans=0;
		for(int i=0;i<10;i++){
			ans+=solve(1, i);
			ans%=mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}

