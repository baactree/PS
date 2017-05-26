// =====================================================================================
// 
//       Filename:  14492.cpp
//        Created:  2017년 05월 26일 15시 13분 20초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int a[300][300];
int b[300][300];
int c[300][300];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d", &a[i][j]);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d", &b[i][j]);
	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			int now=0;
			for(int k=0;k<n;k++)
				now|=(a[i][k]&b[k][j]);
			c[i][j]=now;
			ans+=c[i][j];
		}
	printf("%d\n", ans);
	return 0;
}

