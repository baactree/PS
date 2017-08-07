// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 08월 06일 21시 56분 56초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int h, w;
int n;
int arr[10005];
int mat[100][100];
int idx;
int get_color(){
	while(idx<n&&arr[idx]==0)
		idx++;
	arr[idx]--;
	return idx;
}
int main(){
	scanf("%d%d", &h, &w);
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &arr[i]);
	for(int i=0;i<h;i++){
		if(i&1)
			for(int j=0;j<w;j++)
				mat[i][j]=get_color();
		else
			for(int j=w-1;j>=0;j--)
				mat[i][j]=get_color();
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
	return 0;
}

