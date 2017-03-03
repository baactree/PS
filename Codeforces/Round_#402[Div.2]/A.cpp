// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 03월 02일 14시 43분 23초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int cnt[6];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int in;
		scanf("%d", &in);
		cnt[in]++;
	}
	for(int i=0;i<n;i++){
		int in;
		scanf("%d", &in);
		cnt[in]--;
	}
	int ans=0;
	for(int i=1;i<=5;i++){
		if(abs(cnt[i])%2==1){
			printf("-1\n");
			return 0;
		}
		ans+=abs(cnt[i])/2;
	}
	printf("%d\n", ans/2);
	return 0;
}

