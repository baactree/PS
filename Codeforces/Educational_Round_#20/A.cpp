// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 04월 29일 00시 02분 43초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int ans[100][100];
int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(ans[i][j]==1)
				continue;
			if(k>0&&i==j){
				ans[i][j]=1;
				k--;
				continue;
			}
			if(k>1){
				ans[i][j]=ans[j][i]=1;
				k-=2;
			}
		}
	}
	if(k>0){
		printf("-1\n");
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			printf("%d ", ans[i][j]);
		printf("\n");
	}
	
	return 0;
}

