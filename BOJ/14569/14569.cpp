// =====================================================================================
// 
//       Filename:  14569.cpp
//        Created:  2017년 05월 19일 17시 44분 24초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
long long sub[1000];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int k;
		scanf("%d", &k);
		for(int j=0;j<k;j++){
			int in;
			scanf("%d", &in);
			sub[i]|=(1ll<<in);
		}
	}
	scanf("%d", &m);
	for(int i=0;i<m;i++){
		int k;
		scanf("%d", &k);
		long long now=0;
		for(int j=0;j<k;j++){
			int in;
			scanf("%d", &in);
			now|=(1ll<<in);
		}
		int cnt=0;
		for(int j=0;j<n;j++){
			if(sub[j]==(now&sub[j]))
				cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}

