// =====================================================================================
// 
//       Filename:  6500.cpp
//        Created:  2017년 09월 20일 20시 34분 13초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	string str;
	while(true){
		cin>>str;
		if(str=="0")
			break;
		set<int> s;
		int now=stoi(str);
		while(s.find(now)==s.end()){
			s.insert(now);
			now=now*now%1000000/100;
		}
		printf("%d\n", s.size());
	}
	return 0;
}

