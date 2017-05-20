// =====================================================================================
// 
//       Filename:  1039.cpp
//        Created:  2017년 05월 20일 12시 22분 43초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int cache[1000005][10];
int n, k;
int solve(int state, int idx){
	if(idx==k)
		return state;
	int &ret=cache[state][idx];
	if(ret!=-1)
		return ret;
	string temp=to_string(state);
	for(int i=0;i<temp.size();i++){
		for(int j=i+1;j<temp.size();j++){
			if(i==0&&temp[j]=='0')
				continue;
			swap(temp[i], temp[j]);
			ret=max(ret, solve(stoi(temp), idx+1));
			swap(temp[i], temp[j]);
		}
	}
	return ret;
}
int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d%d", &n, &k);
	int ans=solve(n, 0);
	printf("%d\n", ans);
	return 0;
}

