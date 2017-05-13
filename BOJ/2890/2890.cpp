// =====================================================================================
// 
//       Filename:  2890.cpp
//        Created:  2017년 05월 12일 13시 51분 01초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int ans[10];
int r, c;
char mat[55][55];
int main(){
	scanf("%d%d", &r, &c);
	for(int i=0;i<r;i++)
		scanf("%s", mat[i]);
	int p=1;
	for(int j=c-2;j>0;j--){
		int cnt=0;
		for(int i=0;i<r;i++){
			if(mat[i][j]!='.'){
				int now=mat[i][j]-'0';
				if(ans[now]==0){
					ans[now]=p;
					cnt=1;
				}
			}
		}
		p+=cnt;
	}
	for(int i=1;i<=9;i++)
		printf("%d\n", ans[i]);
	return 0;
}

