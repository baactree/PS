// =====================================================================================
// 
//       Filename:  2863.cpp
//        Created:  2017년 01월 17일 15시 19분 59초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int mat[2][2];
int main(){
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			scanf("%d", &mat[i][j]);
	int ans=0;
	double now=0;
	for(int i=0;i<4;i++){
		double temp=(double)mat[0][0]/mat[1][0]+(double)mat[0][1]/mat[1][1];
		if(now<temp){
			ans=i;
			now=temp;
		}
		int d=mat[0][0];
		mat[0][0]=mat[1][0];
		mat[1][0]=mat[1][1];
		mat[1][1]=mat[0][1];
		mat[0][1]=d;
	}
	printf("%d\n", ans);
	return 0;
}

