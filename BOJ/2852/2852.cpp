// =====================================================================================
// 
//       Filename:  2852.cpp
//        Created:  2017년 04월 13일 19시 04분 38초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int ansa, ansb;
int main(){
	scanf("%d", &n);
	int now=0;
	int sa, sb;
	sa=sb=0;
	for(int i=0;i<n;i++){
		int a, b, c;
		scanf("%d %d:%d", &a, &b, &c);
		int t=b*60+c;
		if(sa>sb){
			ansa+=t-now;
		}
		else if(sb>sa){
			ansb+=t-now;
		}
		now=t;
		if(a==1)
			sa++;
		else
			sb++;
	}
	if(sa>sb){
		ansa+=48*60-now;
	}
	else if(sb>sa){
		ansb+=48*60-now;
	}
	printf("%02d:%02d\n%02d:%02d\n", ansa/60, ansa%60, ansb/60, ansb%60);
	return 0;
}

