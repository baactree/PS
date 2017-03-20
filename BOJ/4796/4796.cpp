// =====================================================================================
// 
//       Filename:  4796.cpp
//        Created:  2017년 03월 20일 19시 11분 30초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int tc=0;
	while(true){
		int l, p, v;
		scanf("%d%d%d", &l, &p, &v);
		if(v==0)
			break;
		printf("Case %d: %d\n",++tc,  v/p*l+min(v%p, l));
	}
	return 0;
}

