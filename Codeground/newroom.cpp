// =====================================================================================
// 
//       Filename:  newroom.cpp
//        Created:  2017년 04월 09일 19시 05분 36초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int mat[100][100];
int main(){
	int TestCase;
	scanf("%d", &TestCase);
	for(int tc=1;tc<=TestCase;tc++){
		scanf("%d", &n);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d", &mat[i][j]);
	}
	return 0;
}

