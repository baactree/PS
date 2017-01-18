// =====================================================================================
// 
//       Filename:  2436.cpp
//        Created:  2017년 01월 18일 22시 52분 19초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int a, b;
short cnt[50000001];
pair<int, int> ans;
int sum=0x3f3f3f3f;
vector<pair<int, int> > p;
void solve(int idx, int a, int b){
	if(idx==p.size()){
		if(a+b<sum){
			sum=a+b;
			if(a>b)
				swap(a,b);
			ans={a, b};
		}
		return;
	}
	solve(idx+1, a*pow(p[idx].first, p[idx].second), b);
	solve(idx+1, a, b*pow(p[idx].first, p[idx].second));
}
int main(){
	scanf("%d%d", &a, &b);
	int tb=b/a;
	int now=2;
	while(tb!=1){
		while(tb%now==0){
			cnt[now]++;
			tb/=now;
		}
		now++;
	}
	for(int i=0;i<50000001;i++)
		if(cnt[i]!=0)
			p.push_back({i, cnt[i]});
	solve(0, a, a);
	printf("%d %d\n", ans.first, ans.second);
	return 0;
}

