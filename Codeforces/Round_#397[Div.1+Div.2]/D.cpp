// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 03월 09일 16시 06분 35초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int f[100005];
int g[100005];
int h[100005];
int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &f[i]);
	int m=0;
	for(int i=1;i<=n;i++){
		if(f[i]!=f[f[i]]){
			printf("-1\n");
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		if(!g[f[i]]){
			m++;
			g[f[i]]=m;
			h[m]=f[i];
		}
	}
	printf("%d\n", m);
	for(int i=1;i<=n;i++)
		printf("%d ", g[f[i]]);
	printf("\n");
	for(int i=1;i<=m;i++)
		printf("%d ", h[i]);
	printf("\n");
	return 0;
}
