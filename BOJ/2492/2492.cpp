// =====================================================================================
// 
//       Filename:  2492.cpp
//        Created:  2017년 09월 19일 19시 26분 49초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m, t, k;
pair<int, int> arr[100];
int main(){
	scanf("%d%d%d%d", &n, &m, &t, &k);
	vector<pair<int, int> > st;
	for(int i=0;i<t;i++){
		scanf("%d%d", &arr[i].first, &arr[i].second);
		st.push_back(arr[i]);
	}
	for(int i=0;i<t;i++)
		for(int j=0;j<t;j++){
			if(i==j)
				continue;
			st.push_back({arr[i].first, arr[j].second});
			st.push_back({arr[j].first, arr[i].second});
		}
	int ans=0;
	int sx, sy;
	sx=sy=-1;
	for(int i=0;i<st.size();i++){
		int x=st[i].first;
		int y=st[i].second;
		int cnt=0;
		for(int j=0;j<t;j++){
			int nx=arr[j].first;
			int ny=arr[j].second;
			if(nx>=x&&nx<=x+k&&ny>=y&&ny<=y+k)
				cnt++;
		}
		if(ans<cnt){
			ans=cnt;
			sx=x;
			sy=y+k;
			if(x+k>n){
				sx-=x+k-n;;
			}
			if(y+k>m){
				sy-=y+k-m;
			}
		}
		cnt=0;
		for(int j=0;j<t;j++){
			int nx=arr[j].first;
			int ny=arr[j].second;
			if(nx>=x-k&&nx<=x&&ny>=y&&ny<=y+k)
				cnt++;
		}
		if(ans<cnt){
			ans=cnt;
			sx=x-k;
			sy=y+k;
			if(x-k<0){
				sx+=-(x-k);
			}
			if(y+k>m){
				sy-=y+k-m;
			}
		}
		cnt=0;
		for(int j=0;j<t;j++){
			int nx=arr[j].first;
			int ny=arr[j].second;
			if(nx>=x-k&&nx<=x&&ny>=y-k&&ny<=y)
				cnt++;
		}
		if(ans<cnt){
			ans=cnt;
			sx=x-k;
			sy=y;
			if(x-k<0){
				sx+=-(x-k);
			}
			if(y-k<0){
				sy+=-(y-k);
			}
		}
		cnt=0;
		for(int j=0;j<t;j++){
			int nx=arr[j].first;
			int ny=arr[j].second;
			if(nx>=x&&nx<=x+k&&ny>=y-k&&ny<=y)
				cnt++;
		}
		if(ans<cnt){
			ans=cnt;
			sx=x;
			sy=y;
			if(x+k>n){
				sx-=x+k-n;
			}
			if(y-k<0){
				sy+=-(y-k);
			}
		}
	}
	printf("%d %d\n", sx, sy);
	printf("%d\n", ans);
	return 0;
}

