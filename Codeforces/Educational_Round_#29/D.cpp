// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 09월 22일 00시 44분 53초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, q, m;
int a[200005];
int main(){
	scanf("%d%d%d", &n, &q, &m);
	for(int i=1;i<=n;i++)
		scanf("%d", &a[i]);
	vector<pair<int, pair<int, int> > > vec;
	while(q--){
		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);
		vec.push_back({t, {l, r}});
	}
	vector<int> b(m);
	for(int i=0;i<m;i++){
		scanf("%d", &b[i]);
	}
	reverse(vec.begin(), vec.end());
	for(int i=0;i<vec.size();i++){
		int t=vec[i].first;
		int l=vec[i].second.first;
		int r=vec[i].second.second;
		vector<int> nb(m);
		for(int j=0;j<m;j++){
			int now=b[j];
			if(l<=now&&now<=r){
				if(t==1){
					if(now>l){
						nb[j]=now-1;
					}
					else
						nb[j]=r;
				}
				else{
					int len=r-l;
					int idx=now-l;
					idx=len-idx;
					nb[j]=l+idx;
				}
			}
			else
				nb[j]=b[j];
		}
		b=nb;
	}
	for(int i=0;i<m;i++)
		printf("%d ", a[b[i]]);
	return 0;
}

