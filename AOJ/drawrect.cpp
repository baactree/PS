// =====================================================================================
// 
//       Filename:  drawrect.cpp
//        Created:  2017년 02월 21일 16시 34분 24초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main(){
	int tc;
	cin>>tc;
	while(tc--){
		int a, b;
		a=b=0;
		for(int i=0;i<3;i++){
			int q, w;
			scanf("%d%d", &q, &w);
			a^=q;
			b^=w;
		}
		printf("%d %d\n", a, b);
	}
	return 0;
}

