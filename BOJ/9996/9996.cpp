// =====================================================================================
// 
//       Filename:  9996.cpp
//        Created:  2017년 01월 15일 18시 22분 31초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int N;
string p;
string f;
int cache[105][105];
int solve(int pidx, int fidx){
	if(pidx==p.size()&&fidx==f.size())
		return true;
	if(pidx==p.size()||fidx==f.size())
		return false;
	int ret=cache[pidx][fidx];
	if(ret!=-1)
		return ret;
	ret=0;
	if(p[pidx]=='*'){
		ret|=solve(pidx+1, fidx);
		ret|=solve(pidx, fidx+1);
	}
	else if(p[pidx]!=f[fidx])
		return ret=false;
	if(p[pidx]==f[fidx])
		ret|=solve(pidx+1, fidx+1);
	return ret;
}
int main(){
	cin>>N>>p;
	while(N--){
		memset(cache, -1, sizeof(cache));
		cin>>f;
		if(solve(0, 0))
			printf("DA\n");
		else 
			printf("NE\n");
	}
	return 0;
}

