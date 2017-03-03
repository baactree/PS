// =====================================================================================
// 
//       Filename:  E.cpp
//        Created:  2017년 02월 21일 13시 56분 08초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int c[61];
int main(){
	for(int i=1;i<=60;i++){
		for(int j=1;j<=60;j++){
			if(j*(j+1)<=i*2)
				c[i]=j;
		}
	}
	int n;
	scanf("%d", &n);
	int ans=0;
	while(n--){
		int s;
		scanf("%d", &s);
		ans^=c[s];
	}
	printf("%s\n", ans?"NO":"YES");
	return 0;
}

