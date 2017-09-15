// =====================================================================================
// 
//       Filename:  4779.cpp
//        Created:  2017년 09월 14일 18시 21분 02초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
bool arr[600000];
void solve(int le, int ri){
	if(ri-le==1){
		arr[le]=true;
		return;
	}
	solve(le, (2*le+ri)/3);
	solve((le+2*ri)/3, ri);
}
int main(){
	int n;
	while(scanf("%d", &n)!=EOF){
		int k=1;
		for(int i=0;i<n;i++)
			k*=3;
		memset(arr, 0, sizeof(arr));
		solve(0, k);
		for(int i=0;i<k;i++)
			if(arr[i])
				printf("-");
			else
				printf(" ");
		printf("\n");
	}
	return 0;
}

