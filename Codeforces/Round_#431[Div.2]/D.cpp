// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 09월 15일 23시 27분 18초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > ve[200005], ho[200005];
const int shift=100000;
int n, w, h;
vector<pair<int, pair<int, int> > > vec;
int main(){
	scanf("%d%d%d", &n, &w, &h);
	for(int i=0;i<n;i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if(a==1)
			ve[b-c+shift].push_back({b, i});
		else
			ho[b-c+shift].push_back({b, i});
		vec.push_back({a, {b, c}});
	}
	for(int i=0;i<200005;i++){
		sort(ve[i].begin(), ve[i].end());
		sort(ho[i].begin(), ho[i].end());
	}
	for(int i=0;i<n;i++){
		int a=vec[i].first;
		int b=vec[i].second.first;
		int c=vec[i].second.second;
		int k=b-c+shift;
		if(a==1){
			int cnt=lower_bound(ve[k].begin(), ve[k].end(), make_pair(vec[i].second.first, i))-ve[k].begin();
			cnt=ve[k].size()-cnt;
			int tcnt=ho[k].size();
			if(tcnt>=cnt){
				int idx=ho[k][cnt-1].second;
				printf("%d %d\n", w, vec[idx].second.first);
			}
			else{
				cnt=ve[k].size()-cnt;
				int idx=ve[k][cnt+tcnt].second;
				printf("%d %d\n", vec[idx].second.first, h);
			}
		}
		else{
			int cnt=lower_bound(ho[k].begin(), ho[k].end(), make_pair(vec[i].second.first, i))-ho[k].begin();
			cnt=ho[k].size()-cnt;
			int tcnt=ve[k].size();
			if(tcnt>=cnt){
				int idx=ve[k][cnt-1].second;
				printf("%d %d\n", vec[idx].second.first, h);
			}
			else{
				cnt=ho[k].size()-cnt;
				int idx=ho[k][cnt+tcnt].second;
				printf("%d %d\n", w, vec[idx].second.first);
			}
		}
	}
	return 0;
}

