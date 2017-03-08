// =====================================================================================
// 
//       Filename:  1543.cpp
//        Created:  2017년 03월 06일 10시 32분 48초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string n, m;
bool possi(int x){
	for(int i=0;i<m.size();i++)
		if(n[i+x]!=m[i])
			return false;
	return true;
}
int main(){
	getline(cin, n);
	getline(cin, m);
	int ans=0;
	for(int i=0;i<=(int)n.size()-(int)m.size();i++)
		if(possi(i)){
			i+=m.size()-1;
			ans++;
		}
	printf("%d\n", ans);
	return 0;
}

