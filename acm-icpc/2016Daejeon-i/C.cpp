// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 09월 16일 20시 46분 10초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, m, k, l;
int dist[10005];
bool trip[10005];
pii lo[10005], hi[10005], st[10005], ed[10005];
const int inf=0x3f3f3f3f;
inline int calc(pii a, pii b){
	int x=a.first-b.first;
	int y=a.second-b.second;
	return x*x+y*y;
}
inline int get_dist(pii a, pii b, pii c, pii d){
	int ret=inf;
	if(a.first>b.first||a.second>b.second)
		swap(a, b);
	if(c.first>d.first||c.second>d.second)
		swap(c, d);
	if(a.second==b.second){
		if((c.first>=a.first&&c.first<=b.first)||(d.first>=a.first&&d.first<=b.first)){
			ret=min({ret, abs(a.second-c.second), abs(a.second-d.second)});
		}
	}
	else{
		if((c.second>=a.second&&c.second<=b.second)||(d.second>=a.second&&d.second<=b.second)){
			ret=min({ret, abs(a.first-c.first), abs(a.first-d.first)});
		}
	}
	swap(a, c);
	swap(b, d);
	if(a.second==b.second){
		if((c.first>=a.first&&c.first<=b.first)||(d.first>=a.first&&d.first<=b.first)){
			ret=min({ret, abs(a.second-c.second), abs(a.second-d.second)});
		}
	}
	else{
		if((c.second>=a.second&&c.second<=b.second)||(d.second>=a.second&&d.second<=b.second)){
			ret=min({ret, abs(a.first-c.first), abs(a.first-d.first)});
		}
	}
	if(ret<inf)
		ret=ret*ret;
	ret=min({ret, calc(a, c), calc(a, d), calc(b, c), calc(b, d)});
	return ret<=l?ret:inf;
}
int main(){
	scanf("%*d%*d%d%d%d%d", &n, &m, &k, &l);
	for(int i=0;i<n;i++)
		scanf("%d%d", &lo[i].first, &lo[i].second);
	for(int i=0;i<m;i++)
		scanf("%d%d", &hi[i].first, &hi[i].second);
	for(int i=1;i<=k;i++)
		scanf("%d%d%d%d", &st[i].first, &st[i].second, &ed[i].first, &ed[i].second);
	memset(dist, 0x3f, sizeof(dist));
	for(int i=0;i+1<n;i++)
		for(int j=1;j<=k;j++){
			dist[j]=min(dist[j], get_dist(lo[i], lo[i+1], st[j], ed[j]));
		}
	for(int i=0;i<k;i++){
		int now=0;
		for(int j=1;j<=k;j++)
			if(!trip[j]&&dist[now]>dist[j])
				now=j;
		if(!now)
			break;
		trip[now]=true;
		for(int j=1;j<=k;j++){
			if(trip[j])
				continue;
			int there_cost=get_dist(st[now], ed[now], st[j], ed[j])+dist[now];
			dist[j]=min(dist[j], there_cost);
		}
	}
	int ans=inf;
	for(int i=1;i<=k;i++){
		if(dist[i]==inf)
			continue;
		for(int j=0;j+1<m;j++)
			ans=min(ans, get_dist(st[i], ed[i], hi[j], hi[j+1])+dist[i]);
	}
	for(int i=0;i+1<n;i++)
		for(int j=0;j+1<m;j++)
			ans=min(ans, get_dist(lo[i], lo[i+1], hi[j], hi[j+1]));
	printf("%d\n", ans==inf?-1:ans);
	return 0;
}

