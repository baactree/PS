// =====================================================================================
// 
//       Filename:  13414.cpp
//        Created:  2017년 04월 03일 11시 32분 05초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int k, l;
map<int, int> m;
int main(){
	scanf("%d%d", &k, &l);
	queue<int> q;
	for(int i=0;i<l;i++){
		int in;
		scanf("%d", &in);
		q.push(in);
		m[in]++;
	}
	while(!q.empty()&&k){
		int now=q.front();
		q.pop();
		if(m[now]!=1){
			m[now]--;
		}
		else{
			m[now]--;
			string out=to_string(now);
			out=string(8-out.size(), '0')+out;
			cout<<out<<'\n';
			k--;
		}
	}
	return 0;
}

