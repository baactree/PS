// =====================================================================================
// 
//       Filename:  2799.cpp
//        Created:  2017년 04월 07일 16시 08분 30초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
string mat[505];
int t[5];
void calc(int x, int y){
	for(int i=0;i<4;i++){
		if(string(mat[x+i].begin()+y, mat[x+i].begin()+y+4)=="...."){
			t[i]++;
			return;
		}
	}
	t[4]++;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n*5+1;i++)
		cin>>mat[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			calc(i*5+1, j*5+1);
	for(int i=0;i<5;i++)
		printf("%d ", t[i]);
	return 0;
}

