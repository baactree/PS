// =====================================================================================
// 
//       Filename:  2828.cpp
//        Created:  2017년 05월 08일 16시 55분 42초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int main(){
	scanf("%d%d%d", &n, &m, &k);
	int st=1;
	int fi=1+m-1;
	int ans=0;
	for(int i=0;i<k;i++){
		int in;
		scanf("%d", &in);
		if(in<st){
			int diff=st-in;
			ans+=diff;
			st-=diff;
			fi-=diff;
		}
		else if(in>fi){
			int diff=in-fi;
			ans+=diff;
			st+=diff;
			fi+=diff;
		}
	}
	printf("%d\n", ans);
	return 0;
}

