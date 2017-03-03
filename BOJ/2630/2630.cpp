// =====================================================================================
// 
//       Filename:  2630.cpp
//        Created:  2017년 01월 14일 20시 36분 56초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int N;
int mat[128][128];

pair<int, int> add(pair<int, int> a, pair<int, int> b){
	return {a.first+b.first, a.second + b.second};
}
pair<int, int> solve(int n, int x, int y){
	if(n==1){
		if(mat[x][y])
			return {0, 1};
		return {1, 0};
	}
	pair<int, int> ret={0, 0};
	int w, b;
	w=b=0;
	for(int i=x;i<x+n;i++)
		for(int j=y;j<y+n;j++){
			if(mat[i][j])
				b++;
			else
				w++;
		}
	if(w==n*n)
		return {1, 0};
	else if(b==n*n)
		return {0, 1};
	ret = add(ret, solve(n/2, x, y));
	ret = add(ret, solve(n/2, x+n/2, y));
	ret = add(ret, solve(n/2, x, y+n/2));
	ret = add(ret, solve(n/2, x+n/2, y+n/2));
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			scanf("%d", &mat[i][j]);
	pair<int, int> ans=solve(N, 0, 0);
	printf("%d\n%d\n", ans.first, ans.second);
	return 0;
}

