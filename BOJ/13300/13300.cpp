// =====================================================================================
// 
//       Filename:  13300.cpp
//        Created:  2017년 03월 11일 18시 52분 30초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
int cnt[2][7];
int main(){
	scanf("%d%d", &n, &k);
	for(int i=0;i<n;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		cnt[a][b]++;
	}
	int ans=0;
	for(int i=0;i<2;i++)
		for(int j=1;j<=6;j++){
			ans+=(int)ceil((double)cnt[i][j]/k);
		}
	printf("%d\n", ans);
	return 0;
}

