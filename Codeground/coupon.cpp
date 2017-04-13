// =====================================================================================
// 
//       Filename:  coupon.cpp
//        Created:  2017년 04월 13일 00시 52분 54초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int dist[101][101];
int n, m, k, p;
int main(){
	int TestCase;
	scanf("%d", &TestCase);
	for(int tc=1;tc<=TestCase;tc++){
		scanf("%d%d%d", &n, &m, &k);
		memset(dist, 0x3f, sizeof(dist));
		for(int i=0;i<m;i++){
			int a, b, d;
			scanf("%d%d%d", &a, &b, &d);
			dist[a][b]=dist[b][a]=d;
		}
		for(int i=1;i<=n;i++)
			dist[i][i]=0;
		for(int q=1;q<=n;q++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					dist[i][j]=min(dist[i][j], dist[i][q]+dist[q][j]);
		scanf("%d", &p);
		int ans=0;
		for(int i=0;i<p;i++){
			int a, b;
			scanf("%d%d", &a, &b);
			if(dist[a][b]>k)
				ans++;
		}
		printf("Case #%d\n%d\n", tc, ans);
	}
	return 0;
}

