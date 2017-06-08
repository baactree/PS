// =====================================================================================
// 
//       Filename:  1895.cpp
//        Created:  2017년 06월 08일 15시 42분 14초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int r, c;
int mat[40][40];
int t;
int calc(int x, int y){
	vector<int> vec;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			vec.push_back(mat[x+i][y+j]);
	nth_element(vec.begin(), vec.begin()+4, vec.end());
	return vec[4];
}
int main(){
	scanf("%d%d", &r, &c);
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			scanf("%d", &mat[i][j]);
	scanf("%d", &t);
	int ans=0;
	for(int i=0;i+3<=r;i++)
		for(int j=0;j+3<=c;j++){
			if(calc(i, j)>=t)
				ans++;
		}
	printf("%d\n", ans);
	return 0;
}

