// =====================================================================================
// 
//       Filename:  14709.cpp
//        Created:  2017년 09월 16일 17시 33분 45초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int cnt[6][6];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		if(a>b)
			swap(a, b);
		cnt[a][b]++;
	}
	if(cnt[1][3]&&cnt[1][4]&&cnt[3][4]&&n==cnt[1][3]+cnt[1][4]+cnt[3][4])
		printf("Wa-pa-pa-pa-pa-pa-pow!\n");
	else
		printf("Woof-meow-tweet-squeek\n");
	return 0;
}

