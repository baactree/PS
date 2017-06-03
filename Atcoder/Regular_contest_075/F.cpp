// =====================================================================================
// 
//       Filename:  F.cpp
//        Created:  2017년 06월 03일 22시 15분 14초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int d;
int main(){
	scanf("%d", &d);
	for(int i=1;i<10000;i++){
		string rev=to_string(i);
		reverse(rev.begin(), rev.end());
		printf("%d : %d\n", i, stoi(rev)-i);
	}
	return 0;
}

