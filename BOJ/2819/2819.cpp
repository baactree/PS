// =====================================================================================
// 
//       Filename:  2819.cpp
//        Created:  2017년 08월 08일 02시 17분 12초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> xidx;
vector<int> yidx;
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
typedef long long ll;
int main(){
	scanf("%d%d", &n, &m);
	ll d=0;
	for(int i=0;i<n;i++){
		int x, y;
		scanf("%d%d", &x, &y);
		xidx.push_back(x);
		yidx.push_back(y);
		d+=abs(x);
		d+=abs(y);
	}
	sort(xidx.begin(), xidx.end());
	sort(yidx.begin(), yidx.end());
	string str;
	cin>>str;
	int x, y;
	x=y=0;
	for(int i=0;i<str.size();i++){
		if(str[i]=='S'){
			int cnt=upper_bound(yidx.begin(), yidx.end(), y)-yidx.begin();
			d+=cnt;
			d-=n-cnt;
			y++;
		}
		else if(str[i]=='J'){
			int cnt=lower_bound(yidx.begin(), yidx.end(), y)-yidx.begin();
			d-=cnt;
			d+=n-cnt;
			y--;
		}
		else if(str[i]=='I'){
			int cnt=upper_bound(xidx.begin(), xidx.end(), x)-xidx.begin();
			d+=cnt;
			d-=n-cnt;
			x++;
		}
		else{
			int cnt=lower_bound(xidx.begin(), xidx.end(), x)-xidx.begin();
			d-=cnt;
			d+=n-cnt;
			x--;
		}
		printf("%lld\n", d);
	}
	return 0;
}

