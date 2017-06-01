// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 06월 01일 22시 50분 50초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int mat[4][4];
int main(){
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			scanf("%d", &mat[i][j]);
	bool flag=false;
	if(mat[0][3]){
		if(mat[0][0]||mat[0][1]||mat[0][2]||mat[1][0]||mat[2][1]||mat[3][2])
			flag=true;
	}
	if(mat[1][3]){
		if(mat[1][0]||mat[1][1]||mat[1][2]||mat[0][2]||mat[2][0]||mat[3][1])
			flag=true;
	}
	if(mat[2][3]){
		if(mat[2][0]||mat[2][1]||mat[2][2]||mat[0][1]||mat[1][2]||mat[3][0])
			flag=true;
	}
	if(mat[3][3]){
		if(mat[3][0]||mat[3][1]||mat[3][2]||mat[0][0]||mat[1][1]||mat[2][2])
			flag=true;
	}
	printf("%s\n", flag?"YES":"NO");
	return 0;
}

