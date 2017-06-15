// =====================================================================================
// 
//       Filename:  2461.cpp
//        Created:  2017년 06월 15일 03시 49분 03초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int pick;
int cnt[1000];
vector<pair<int, int> > arr;
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			int in;
			scanf("%d", &in);
			arr.push_back({in, i});
		}
	sort(arr.begin(), arr.end());
	int st, fi;
	int ans=1e9;
	st=fi=0;

	while(true){
		if(pick==n){
			ans=min(ans, arr[fi-1].first-arr[st].first);
			cnt[arr[st].second]--;
			if(cnt[arr[st].second]==0)
				pick--;
			st++;
		}
		else if(fi<n*m){
			cnt[arr[fi].second]++;
			if(cnt[arr[fi].second]==1)
				pick++;
			fi++;
		}
		else 
			break;
	}
	printf("%d\n", ans);
	return 0;
}

