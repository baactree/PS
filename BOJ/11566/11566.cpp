// =====================================================================================
// 
//       Filename:  11566.cpp
//        Created:  2017년 09월 30일 17시 28분 52초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1005], b[1005];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	for(int i=0;i<m;i++)
		scanf("%d", &b[i]);
	int minl, maxl;
	minl=0x3f3f3f3f;
	maxl=-0x3f3f3f3f;
	for(int d=0;n+d*(n-1)<=m;d++){
		bool flag=false;
		for(int i=0;i+n+d*(n-1)<=m;i++){
			bool flag2=false;
			for(int j=0;j<n;j++){
				if(b[i+j*d+j]!=a[j]){
					flag2=true;
					break;
				}
			}
			if(!flag2)
				flag=true;
		}
		if(flag){
			minl=min(minl, d);
			maxl=max(maxl, d);
		}
	}
	if(minl==0x3f3f3f3f)
		return !printf("-1\n");
	printf("%d %d\n", minl, maxl);
	return 0;
}

