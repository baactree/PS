// =====================================================================================
// 
//       Filename:  1374.cpp
//        Created:  2017년 06월 27일 11시 33분 20초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > events;
int n;
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		events.push_back({b, 1});
		events.push_back({c, 0});
	}
	int cnt=0;
	int ans=0;
	sort(events.begin(), events.end());
	for(int i=0;i<events.size();i++){
		int a=events[i].first;
		int b=events[i].second;
		if(b==1){
			cnt++;
		}
		else{
			cnt--;
		}
		ans=max(ans, cnt);
	}
	printf("%d\n", ans);
	return 0;
}

