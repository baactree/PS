// =====================================================================================
// 
//       Filename:  14226.cpp
//        Created:  2017년 05월 01일 16시 11분 00초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int s;
bool trip[3000][3000];
int main(){
	scanf("%d", &s);
	queue<pair<int, pair<int, int> > > q;
	q.push({1, {0, 0}});
	trip[1][0]=true;
	while(!q.empty()){
		int now=q.front().first;
		int clip=q.front().second.first;
		int cnt=q.front().second.second;
		q.pop();
		if(now==s){
			printf("%d\n", cnt);
			return 0;
		}
		if(!trip[now][now]){
			q.push({now, {now, cnt+1}});
			trip[now][now]=true;
		}
		if(now+clip<3000&&!trip[now+clip][clip]){
			q.push({now+clip, {clip, cnt+1}});
			trip[now+clip][clip]=true;
		}
		if(now>0&&!trip[now-1][clip]){
			q.push({now-1, {clip, cnt+1}});
			trip[now-1][clip]=true;
		}
	}
	return 0;
}

