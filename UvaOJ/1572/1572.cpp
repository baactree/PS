// =====================================================================================
// 
//       Filename:  1572.cpp
//        Created:  2017년 05월 08일 21시 20분 07초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int mat[60][60];
int calc(char a, char b){
	return (a-'A')*2+(b=='+'?1:0);
}
int main() {
    while(scanf("%d", &n) !=EOF) {
		memset(mat, 0x3f, sizeof(mat));
		for(int i=0;i<n;i++){
			char m[10];
			scanf("%s", m);
			for(int j=0;j<4;j++)
				for(int k=0;k<4;k++){
					if(j==k)
						continue;
					if(m[j*2]=='0'||m[k*2]=='0')
						continue;
					int u=calc(m[j*2], m[j*2+1]);
					int v=calc(m[k*2], m[k*2+1])^1;
					mat[u][v]=1;
				}
		}
		for(int k=0;k<60;k++)
			for(int i=0;i<60;i++)
				for(int j=0;j<60;j++)
					mat[i][j]=min(mat[i][j], mat[i][k]+mat[k][j]);
		bool ans=false;
		for(int i=0;i<60;i++)
			if(mat[i][i]!=0x3f3f3f3f)
				ans=true;
		printf("%s\n", ans?"unbounded":"bounded");
    }
    return 0;
}
