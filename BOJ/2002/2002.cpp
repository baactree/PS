// =====================================================================================
// 
//       Filename:  2002.cpp
//        Created:  2017년 08월 29일 00시 04분 04초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
map<string, int> mp;
int in[1000], out[1000];
int io[1000];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		in[i]=i;
		string x;
		cin>>x;
		mp[x]=i;
	}
	for(int i=0;i<n;i++){
		string x;
		cin>>x;
		out[i]=mp[x];
		io[out[i]]=i;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		set<int> s;
		for(int j=0;j<i;j++)
			s.insert(in[j]);
		for(int j=0;j<io[i];j++)
			s.erase(out[j]);
		if(!s.empty())
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}

