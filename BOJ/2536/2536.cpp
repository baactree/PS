// =====================================================================================
// 
//       Filename:  2536.cpp
//        Created:  2017년 03월 07일 17시 23분 40초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int sx, sy, fx, fy;
struct Bus{
	int num, sx, sy, fx, fy;
};
Bus bus[5000];
int dist[5005];
bool cross(int s, int t){
	if(bus[s].sx==bus[s].fx){
		if(bus[t].sx==bus[t].fx){
			if(bus[s].sx==bus[t].sx){
				if(bus[s].sy<=bus[t].sy&&bus[t].sy<=bus[s].fy)
					return true;
				if(bus[t].sy<=bus[s].sy&&bus[s].sy<=bus[t].fy)
					return true;
			}
			return false;
		}
		if(bus[s].sy<=bus[t].sy&&bus[t].sy<=bus[s].fy&&bus[t].sx<=bus[s].sx&&bus[s].sx<=bus[t].fx)
			return true;
		return false;
	}
	if(bus[t].sy==bus[t].fy){
		if(bus[s].sy==bus[t].sy){
			if(bus[s].sx<=bus[t].sx&&bus[t].sx<=bus[s].fx)
				return true;
			if(bus[t].sx<=bus[s].sx&&bus[s].sx<=bus[t].fx)
				return true;
		}
		return false;
	}
	if(bus[s].sx<=bus[t].sx&&bus[t].sx<=bus[s].fx&&bus[t].sy<=bus[s].sy&&bus[s].sy<=bus[t].fy)
		return true;
	return false;
}
bool cross(int s, int x, int y){
	return bus[s].sx<=x&&x<=bus[s].fx&&bus[s].sy<=y&&y<=bus[s].fy;
}
bool trip[5005];
int main(){
	scanf("%d%d%d", &m, &n, &k);
	for(int i=0;i<k;i++){
		scanf("%d%d%d%d%d", &bus[i].num, &bus[i].sx, &bus[i].sy, &bus[i].fx, &bus[i].fy);
		if(bus[i].sx>bus[i].fx)
			swap(bus[i].sx, bus[i].fx);
		if(bus[i].sy>bus[i].fy)
			swap(bus[i].sy, bus[i].fy);
	}
	scanf("%d%d%d%d", &sx, &sy, &fx, &fy);
	queue<pair<int, int> > q;
	q.push({k, 0});
	trip[k]=true;
	int ans;
	while(!q.empty()){
		int now=q.front().first;
		int cost=q.front().second;
		q.pop();
		if(now==k+1){
			ans=cost;
		}
		if(now==k){
			for(int i=0;i<k;i++)
				if(!trip[i]&&cross(i, sx, sy)){
					trip[i]=true;
					q.push({i, cost+1});
				}
		}
		else{
			for(int i=0;i<k;i++){
				if(i==now)
					continue;
				if(!trip[i]&&cross(i, now)){
					trip[i]=true;
					q.push({i, cost+1});
				}
			}
			if(!trip[k+1]&&cross(now, fx, fy)){
				trip[k+1]=true;
				q.push({k+1, cost+1});
			}
		}
	}
	printf("%d\n", ans-1);
	return 0;
}

