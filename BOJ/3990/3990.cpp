// =====================================================================================
// 
//       Filename:  3990.cpp
//        Created:  2017년 05월 02일 17시 36분 19초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int h[100000];
int n, m;
double r[1001];
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)
		scanf("%d", &h[i]);
	for(int i=0;i<=1000;i++){
		double sum=0;
		for(int j=1;j<n;j++){

		}
		r[i]=sum;
	}
	for(int i=0;i<m;i++){
		char order[2];
		scanf("%s", order);
		if(order[0]=='Q'){
			int a;
			scanf("%d", &a);
			printf("%lf\n", r[a]);
		}
		else{
			int a, b;
			scanf("%d%d", &a, &b);
			h[a]=b;
			if(a-1>=0){
				int lo=min(h[a-1], h[a]);
				int ri=max(h[a-1], h[a]);
				for(int j=lo;j<=ri;j++){

				}
			}
		}
	}
	return 0;
}

