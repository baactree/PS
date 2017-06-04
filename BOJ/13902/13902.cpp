// =====================================================================================
// 
//       Filename:  13902.cpp
//        Created:  2017년 06월 04일 18시 15분 44초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int s[1000];
vector<int> vec;
int inf=0x3f3f3f3f;
int cache[10005];
int solve(int now){
	if(now==0)
		return 0;
	int &ret=cache[now];
	if(ret!=-1)
		return ret;
	ret=inf;
	for(int i=0;i<vec.size();i++){
		if(now-vec[i]>=0)
			ret=min(ret, solve(now-vec[i])+1);
	}
	return ret;
}
int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d%d", &n, &m);
	for(int i=0;i<m;i++){
		scanf("%d", &s[i]);
		vec.push_back(s[i]);
	}
	for(int i=0;i<m;i++)
		for(int j=i+1;j<m;j++)
			vec.push_back(s[i]+s[j]);
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for(int i=0;i<vec.size();i++){
		if(vec[i]>n){
			vec.erase(vec.begin()+i, vec.end());
			break;
		}
	}
	int ans=solve(n);
	printf("%d\n", ans==inf?-1:ans);
	return 0;
}

