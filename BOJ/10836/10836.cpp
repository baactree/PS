// =====================================================================================
// 
//       Filename:  10836.cpp
//        Created:  2017년 04월 13일 18시 27분 32초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int m, n;
int mat[700][700];
int tree[1500];
void update(int idx, int val){
	while(idx<1500){
		tree[idx]+=val;
		idx+=idx&(-idx);
	}
}
int query(int idx){
	int ret=0;
	while(idx){
		ret+=tree[idx];
		idx-=idx&(-idx);
	}
	return ret;
}
int main(){
	scanf("%d%d", &m, &n);
	update(1, 1);
	for(int i=0;i<n;i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		update(a+1, 1);
		update(a+b+1, 1);
	}
	for(int i=0;i<m;i++)
		mat[m-1-i][0]=query(i+1);
	for(int i=0;i<m;i++)
		for(int j=1;j<m;j++)
			mat[i][j]=query(m+j);
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
	return 0;
}

