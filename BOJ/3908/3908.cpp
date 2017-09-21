// =====================================================================================
// 
//       Filename:  3908.cpp
//        Created:  2017년 09월 21일 19시 26분 05초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
bool prime[2000];
vector<int> p;
int n, k;
int cache[200][1200][15];
int solve(int idx, int sum, int cnt){
	if(sum==0&&cnt==0)
		return 1;
	if(idx==p.size()||sum<0||cnt<0)
		return 0;
	int &ret=cache[idx][sum][cnt];
	if(ret!=-1)
		return ret;
	ret=solve(idx+1, sum, cnt);
	ret+=solve(idx+1, sum-p[idx], cnt-1);
	return ret;
}
int main(){
	for(int i=2;i<1200;i++){
		if(!prime[i]){
			p.push_back(i);
			for(int j=i*i;j<1200;j+=i)
				prime[j]=true;
		}
	}
	memset(cache, -1, sizeof(cache));
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		scanf("%d%d", &n, &k);
		printf("%d\n", solve(0, n, k));
	}
	return 0;
}

