// =====================================================================================
// 
//       Filename:  14710.cpp
//        Created:  2017년 09월 16일 17시 44분 12초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
bool chk[360][360];
int main(){
	int a, b;
	a=b=0;
	for(int i=0;i<360;i++){
		chk[a][b]=true;
		a=(a+1)%360;
		b=(b+12)%360;
	}
	scanf("%d%d", &a, &b);
	printf("%s\n", chk[a][b]?"O":"X");
	return 0;
}

