// =====================================================================================
// 
//       Filename:  11509.cpp
//        Created:  2017년 03월 26일 20시 15분 13초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int st[1000001];
int main(){
	scanf("%d", &n);
	int cnt=0;
	for(int i=0;i<n;i++){
		int in;
		scanf("%d", &in);
		if(st[in+1]==0){
			st[in]++;
			cnt++;
			continue;
		}
		st[in+1]--;
		st[in]++;
	}
	printf("%d\n", cnt);
	return 0;
}

