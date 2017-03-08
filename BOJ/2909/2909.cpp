// =====================================================================================
// 
//       Filename:  2909.cpp
//        Created:  2017년 03월 07일 16시 49분 34초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int c, k;
int main(){
	scanf("%d%d", &c, &k);
	for(int i=0;i<k;i++){
		if(i==k-1)
			c+=5;
		c/=10;
	}
	for(int i=0;i<k;i++)
		c*=10;
	printf("%d\n", c);
	return 0;
}

