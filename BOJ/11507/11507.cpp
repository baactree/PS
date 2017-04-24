// =====================================================================================
// 
//       Filename:  11507.cpp
//        Created:  2017년 04월 25일 00시 16분 13초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
char in;
int p;
int check[255][15];
int cnt[4]={13, 13, 13, 13};
char q[4]={'P', 'K', 'H', 'T'};
int main(){
	while(scanf("%c", &in)!=EOF&&scanf("%2d", &p)!=EOF){
		if(check[in][p]){
			printf("GRESKA\n");
			return 0;
		}
		check[in][p]=true;
	}
	for(int i=0;i<4;i++)
		for(int j=1;j<=13;j++)
			if(check[q[i]][j])
				cnt[i]--;
	for(int i=0;i<4;i++)
		printf("%d ", cnt[i]);
	printf("\n");
	return 0;
}

