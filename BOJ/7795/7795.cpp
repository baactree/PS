// =====================================================================================
// 
//       Filename:  7795.cpp
//        Created:  2017년 03월 20일 19시 07분 33초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int a[20000];
int b[20000];
int n, m;
int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		scanf("%d%d", &n, &m);
		for(int i=0;i<n;i++)
			scanf("%d", &a[i]);
		for(int i=0;i<m;i++)
			scanf("%d", &b[i]);
		sort(b, b+m);
		int ans=0;
		for(int i=0;i<n;i++){
			int idx=lower_bound(b, b+m, a[i])-b;
			ans+=idx;
		}
		printf("%d\n", ans);
	}
	return 0;
}

