// =====================================================================================
// 
//       Filename:  1285.cpp
//        Created:  2017년 05월 14일 20시 11분 04초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
char mat[25][25];
bool coin[25][25];
int solve(int idx){
	if(idx==n){
		int ret=0;
		for(int i=0;i<n;i++){
			int cnt=0;
			for(int j=0;j<n;j++)
				cnt+=coin[j][i];
			if(cnt>n-cnt)
				ret+=n-cnt;
			else
				ret+=cnt;
		}
		return ret;
	}
	int ret=0x3f3f3f3f;
	ret=min(ret, solve(idx+1));
	for(int i=0;i<n;i++)
		coin[idx][i]=!coin[idx][i];
	ret=min(ret, solve(idx+1));
	for(int i=0;i<n;i++)
		coin[idx][i]=!coin[idx][i];
	return ret;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%s", mat[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			coin[i][j]=mat[i][j]=='T';
	printf("%d\n", solve(0));
	return 0;
}

