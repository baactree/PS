// =====================================================================================
// 
//       Filename:  2957.cpp
//        Created:  2017년 05월 11일 18시 32분 07초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int depth[300001];
pair<bool, bool> child[300001];
set<int> s;
int main(){
	long long ans=0;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int in;
		scanf("%d", &in);
		if(s.empty()){
			s.insert(in);
			depth[in]=1;
		}
		else{
			auto it=s.lower_bound(in);
			if(it!=s.end()){
				int now=*it;
				if(!child[now].first){
					child[now].first=true;
					depth[in]=depth[now]+1;
					ans+=depth[now];
				}
			}
			if(it!=s.begin()){
				it--;
				int now=*it;
				if(!child[now].second){
					child[now].second=true;
					depth[in]=depth[now]+1;
					ans+=depth[now];
				}
			}
			s.insert(in);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

