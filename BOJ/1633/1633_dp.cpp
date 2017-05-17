// =====================================================================================
// 
//       Filename:  1633_dp.cpp
//        Created:  2017년 05월 15일 02시 23분 13초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > arr;
int cache[1010][20][20];
int solve(int idx, int b, int w){
	if(idx==arr.size()){
		if(b==15&&w==15)
			return 0;
		return -0x3f3f3f3f;
	}
	int &ret=cache[idx][b][w];
	if(ret!=-1)
		return ret;
	ret=max(ret, solve(idx+1, b, w));
	if(b!=15)
		ret=max(ret, solve(idx+1, b+1, w)+arr[idx].second);
	if(w!=15)
		ret=max(ret, solve(idx+1, b, w+1)+arr[idx].first);
	return ret;
}
int main(){
	int b, w;
	while(scanf("%d%d", &w, &b)!=EOF)
		arr.push_back({w, b});
	memset(cache, -1, sizeof(cache));
	printf("%d\n", solve(0, 0, 0));
	return 0;
}

