// =====================================================================================
// 
//       Filename:  1058.cpp
//        Created:  2017년 03월 11일 19시 59분 02초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
char mat[50][51];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%s", mat[i]);

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if(mat[i][j]=='N')
				mat[i][j]=0x3f;
			else
				mat[i][j]=1;
		}
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				if(i==j)
					continue;
				mat[i][j]=min(mat[i][j], (char)(mat[i][k]+mat[k][j]));
			}
	int ans=0;
	for(int i=0;i<n;i++){
		int cnt=0;
		for(int j=0;j<n;j++){
			if(i==j)
				continue;
			if(mat[i][j]<=2)
				cnt++;
		}
		ans=max(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}

