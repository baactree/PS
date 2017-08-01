// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 07월 31일 23시 44분 08초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, q, c;
int sum[11][105][105];
int get_cnt(int t, int x1, int y1, int x2, int y2){
	return sum[t][x2][y2]-sum[t][x2][y1-1]-sum[t][x1-1][y2]+sum[t][x1-1][y1-1];
}
int main(){
	scanf("%d%d%d", &n, &q, &c);
	for(int i=0;i<n;i++){
		int x, y, s;
		scanf("%d%d%d", &x, &y, &s);
		sum[s][x][y]++;
	}
	for(int i=0;i<=c;i++){
		for(int x=1;x<105;x++)
			for(int y=1;y<105;y++)
				sum[i][x][y]+=sum[i][x][y-1];
		for(int y=1;y<105;y++)
			for(int x=1;x<105;x++)
				sum[i][x][y]+=sum[i][x-1][y];
	}
	while(q--){
		int t, x1, y1, x2, y2;
		scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
		int ans=0;
		t%=c+1;
		for(int i=0;i<=c;i++){
			int cnt=get_cnt(i, x1, y1, x2, y2);
			ans+=cnt*((i+t)%(c+1));
		}
		printf("%d\n", ans);
	}
	return 0;
}

