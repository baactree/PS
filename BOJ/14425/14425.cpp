// =====================================================================================
// 
//       Filename:  14425.cpp
//        Created:  2017년 08월 09일 13시 00분 48초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
set<string> s;
int main(){
	scanf("%d%d", &n, &m);
	while(n--){
		string in;
		cin>>in;
		s.insert(in);
	}
	int ans=0;
	while(m--){
		string in;
		cin>>in;
		if(s.find(in)!=s.end())
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}

