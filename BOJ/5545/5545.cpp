// =====================================================================================
// 
//       Filename:  5545.cpp
//        Created:  2017년 03월 08일 20시 02분 14초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, a, b, c;
int d[100];
int main(){
	scanf("%d%d%d%d", &n, &a, &b, &c);
	for(int i=0;i<n;i++)
		scanf("%d", &d[i]);
	sort(d, d+n);
	int p, q;
	p=a;
	q=c;
	for(int i=n-1;i>=0;i--){
		if(q*(p+b)<=(q+d[i])*p){
			q+=d[i];
			p+=b;
		}
	}
	printf("%d\n", q/p);
	return 0;
}

