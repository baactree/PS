// =====================================================================================
// 
//       Filename:  1392.cpp
//        Created:  2017년 05월 02일 01시 36분 03초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, q;
int t[10005];
int main(){
	scanf("%d%d", &n, &q);
	int now=0;
	for(int i=0;i<n;i++){
		int in;
		scanf("%d", &in);
		for(int j=0;j<in;j++)
			t[now++]=i+1;
	}
	for(int i=0;i<q;i++){
		int in;
		scanf("%d", &in);
		printf("%d\n", t[in]);
	}
	return 0;
}

