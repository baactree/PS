// =====================================================================================
// 
//       Filename:  10709.cpp
//        Created:  2017년 04월 09일 17시 50분 06초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int h, w;
char mat[100][101];
int ans[100][100];
int main(){
	scanf("%d%d", &h, &w);
	for(int i=0;i<h;i++)
		scanf("%s", mat[i]);
	memset(ans, -1, sizeof(ans));
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++){
			if(mat[i][j]=='.')
				continue;
			else
				for(int k=0;j+k<w;k++){
					ans[i][j+k]=k;
				}
		}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			printf("%d", ans[i][j]);
			if(j!=w-1)
				printf(" ");
		}
		if(i!=h-1)
			printf("\n");
	}
	return 0;
}

