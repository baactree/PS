// =====================================================================================
// 
//       Filename:  13133.cpp
//        Created:  2017년 03월 31일 17시 25분 37초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> arr[501];
int state[501];
int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d%d", &arr[i].first, &arr[i].second);
	}
	scanf("%d", &m);
	for(int i=0;i<m;i++){
		int in;
		scanf("%d", &in);
		state[in]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(arr[i].first!=0&&arr[i].second!=0&&!state[i]
				&&!state[arr[i].first]&&!state[arr[i].second])
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}

