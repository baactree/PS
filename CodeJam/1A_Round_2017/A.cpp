// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 04월 15일 09시 55분 51초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int R, C;
char mat[30][30];
int main(){

	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int TestCase;
	scanf("%d", &TestCase);
	  
	for(int tc=1;tc<=TestCase;tc++){
		//in>>R>>C;
		scanf("%d%d", &R, &C);
		for(int i=0;i<R;i++)
			//in>>mat[i];
			scanf("%s", mat[i]);
	
		for(int i=0;i<R;i++)
			for(int j=1;j<C;j++)
				if(mat[i][j]=='?')
					mat[i][j]=mat[i][j-1];
		for(int i=0;i<R;i++)
			for(int j=C-2;j>=0;j--)
				if(mat[i][j]=='?')
					mat[i][j]=mat[i][j+1];
		for(int i=1;i<R;i++)
			for(int j=0;j<C;j++)
				if(mat[i][j]=='?')
					mat[i][j]=mat[i-1][j];
		for(int i=R-2;i>=0;i--)
			for(int j=0;j<C;j++)
				if(mat[i][j]=='?')
					mat[i][j]=mat[i+1][j];

		//out<<"Case #"<<tc<<":\n";
		printf("Case #%d:\n", tc);
		for(int i=0;i<R;i++){
			//out<<mat[i]<<'\n';
			printf("%s\n", mat[i]);
		}
	}
	
	return 0;
}

