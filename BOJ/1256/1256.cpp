// =====================================================================================
// 
//       Filename:  1256.cpp
//        Created:  2017년 05월 28일 19시 08분 24초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int cache[105][105];
int n, m, k;
int max_value=1e9+10;
int solve(int nidx, int midx){
	if(nidx==0&&midx==0)
		return 1;
	int &ret=cache[nidx][midx];
	if(ret!=-1)
		return ret;
	ret=0;
	if(nidx>0){
		ret+=solve(nidx-1, midx);
		ret=min(ret, max_value);
	}
	if(midx>0){
		ret+=solve(nidx, midx-1);
		ret=min(ret, max_value);
	}
	return ret;
}
string get_ans(int nidx, int midx, int kidx){
	if(nidx==0&&midx==0)
		return "";
	if(nidx>0){
		int a=solve(nidx-1, midx);
		if(a>=kidx)
			return "a"+get_ans(nidx-1, midx, kidx);
		return "z"+get_ans(nidx, midx-1, kidx-a);
	}
	return "z"+get_ans(nidx, midx-1, kidx);
}
int main(){
	scanf("%d%d%d", &n, &m, &k);
	memset(cache, -1, sizeof(cache));
	int cnt=solve(n, m);

	if(cnt<k){
		printf("-1\n");
		return 0;
	}
	cout<<get_ans(n, m, k)<<endl;
	return 0;
}

