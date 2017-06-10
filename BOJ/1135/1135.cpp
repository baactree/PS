// =====================================================================================
// 
//       Filename:  1135.cpp
//        Created:  2017년 06월 10일 13시 38분 55초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
vector<int> adj[50];
int n;
int solve(int now){
	vector<int> vec;
	for(int i=0;i<adj[now].size();i++){
		int there=adj[now][i];
		int temp=solve(there);
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end());
	int ret=0;
	for(int i=0;i<vec.size();i++)
		ret=max(ret, vec[i]+(int)vec.size()-i);
	return ret;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int in;
		scanf("%d", &in);
		if(in!=-1)
			adj[in].push_back(i);
	}
	printf("%d\n", solve(0));
	return 0;
}

