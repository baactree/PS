// =====================================================================================
// 
//       Filename:  2647.cpp
//        Created:  2017년 09월 16일 19시 02분 57초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
string str;
int cache[105][105];
const int inf=0x3f3f3f3f;
vector<pair<int, int> > ans;
int solve(int le, int ri){
	if(le>ri)
		return 0;
	int &ret=cache[le][ri];
	if(ret!=-1)
		return ret;
	ret=inf;
	int cnt=str[le]=='1'?1:-1;
	int len=1;
	for(int i=le+1;i<=ri;i++){
		cnt+=(str[i]=='1'?1:-1);
		len=max(len, abs(cnt));
		if(!cnt){
			ret=min(ret, solve(le+1, i-1)+solve(i+1, ri)+i-le+len*2);
		}
	}
	return ret;
}
void get_ans(int le, int ri){
	if(le>ri)
		return;
	int ret=inf;
	int idx=-1;
	int cnt=str[le]=='1'?1:-1;
	int len=1;
	for(int i=le+1;i<=ri;i++){
		cnt+=(str[i]=='1'?1:-1);
		len=max(len, abs(cnt));
		if(!cnt){
			if(ret>solve(le+1, i-1)+solve(i+1, ri)+i-le+len*2){
				ret=solve(le+1, i-1)+solve(i+1, ri)+i-le+len*2;
				idx=i;
			}
		}
	}
	ans.push_back({le+1, idx+1});
	get_ans(le+1, idx-1);
	get_ans(idx+1, ri);
}
int main(){
	cin>>n>>str;
	memset(cache, -1, sizeof(cache));
	printf("%d\n", solve(0, str.size()-1));
	get_ans(0, str.size()-1);
	sort(ans.begin(), ans.end());
	for(int i=0;i<ans.size();i++)
		printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}

