// =====================================================================================
// 
//       Filename:  3991.cpp
//        Created:  2017년 08월 05일 12시 14분 11초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int h, w, c;
int mat[10][10];
int main(){
	scanf("%d%d%d", &h, &w, &c);
	vector<int> vec;
	for(int i=1;i<=c;i++){
		int x;
		scanf("%d", &x);
		while(x--)
			vec.push_back(i);
	}
	int idx=0;
	for(int i=0;i<h;i++){
		if(i&1){
			for(int j=w-1;j>=0;j--){
				mat[i][j]=vec[idx++];
			}
		}
		else{
			for(int j=0;j<w;j++){
				mat[i][j]=vec[idx++];
			}
		}
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++)
			printf("%d", mat[i][j]);
		printf("\n");
	}
	return 0;
}

