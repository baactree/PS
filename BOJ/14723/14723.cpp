// =====================================================================================
// 
//       Filename:  14723.cpp
//        Created:  2017년 09월 21일 09시 29분 36초
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
	int a, b;
	a=b=1;
	int r=1;
	for(int i=1;i<n;i++){
		if(a==1){
			b=1;
			a=++r;
		}
		else{
			a--;
			b++;
		}
	}
	printf("%d %d\n", a, b);
	return 0;
}

