// =====================================================================================
// 
//       Filename:  1099.cpp
//        Created:  2017년 05월 03일 15시 18분 47초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int cache[50];
int n;
string str;
string arr[50];
int cnt[50][26];
bool possi(int x, const vector<int> &ncnt){
	for(int i=0;i<26;i++)
		if(cnt[x][i]!=ncnt[i])
			return false;
	return true;
}
int calc(int idx, int x){
	int ret=0;
	for(int i=0;i<arr[x].size();i++)
		if(arr[x][i]!=str[idx+i])
			ret++;
	return ret;
}
int solve(int idx){
	if(idx==str.size())
		return 0;
	int &ret=cache[idx];
	if(ret!=-1)
		return ret;
	vector<int> ncnt(26, 0);
	ret=inf;
	for(int i=idx;i<str.size();i++){
		ncnt[str[i]-'a']++;
		for(int j=0;j<n;j++)
			if(possi(j, ncnt))
				ret=min(ret, solve(i+1)+calc(idx, j));
	}
	return ret;
}
int main(){
	memset(cache, -1, sizeof(cache));
	cin>>str;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
		for(int j=0;j<arr[i].size();j++)
			cnt[i][arr[i][j]-'a']++;
	}
	int ans=solve(0);
	printf("%d\n", ans==inf?-1:ans);
	return 0;
}

