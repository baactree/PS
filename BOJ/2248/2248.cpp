// =====================================================================================
// 
//       Filename:  2248.cpp
//        Created:  2017년 05월 19일 00시 31분 05초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k;
ll cache[32][32];
ll solve(int idx, int cnt){
	if(idx==n)
		return 1;
	ll &ret=cache[idx][cnt];
	if(ret!=-1)
		return ret;
	ret=solve(idx+1, cnt);
	if(cnt<m)
		ret+=solve(idx+1, cnt+1);
	return ret;
}
string get_ans(int idx, int cnt, ll p){
	if(idx==n)
		return "";
	if(p==0)
		return "";
	ll temp1=solve(idx+1, cnt);
	if(p<=temp1){
		return "0"+get_ans(idx+1, cnt, p);
	}
	else{
		return "1"+get_ans(idx+1, cnt+1, p-temp1);
	}
}
int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%lld%lld%lld", &n, &m, &k);
	solve(0, 0);

	cout<<get_ans(0, 0, k)<<endl;
	return 0;
}

