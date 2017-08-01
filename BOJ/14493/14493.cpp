// =====================================================================================
// 
//       Filename:  14493.cpp
//        Created:  2017년 07월 31일 17시 19분 30초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d", &n);
	int now=0;
	while(n--){
		int a, b;
		scanf("%d%d", &a, &b);
		int m=now%(a+b);
		if(m<b){
			now+=b-m;
		}
		now++;
	}
	printf("%d\n", now);
	return 0;
}

