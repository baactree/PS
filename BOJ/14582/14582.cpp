// =====================================================================================
// 
//       Filename:  14582.cpp
//        Created:  2017년 05월 21일 13시 32분 33초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int a[10];
int b[10];
int sa, sb;
int main(){
	bool flag=false;
	for(int i=0;i<9;i++)
		scanf("%d", &a[i]);
	for(int j=0;j<9;j++)
		scanf("%d", &b[j]);
	for(int i=0;i<9;i++){
		sa+=a[i];
		if(sa>sb)
			flag=true;
		sb+=b[i];
	}
	printf("%s\n", flag?"Yes":"No");
	return 0;
}

