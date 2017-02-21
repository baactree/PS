// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 02월 21일 01시 49분 30초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k, x;
int num[2][2050];
int main(){
	scanf("%d%d%d", &n, &k, &x);
	for(int i=0;i<n;i++){
		int now;
		scanf("%d", &now);
		num[0][now]++;
	}

	for(int i=0;i<k;i++){
		bool odd=true;
		for(int j=0;j<2050;j++)
			num[(i+1)&1][j]=0;
		for(int j=0;j<2050;j++){
			if(num[i&1][j]){
				printf("%d ", j);
				if(odd){
					if(num[i&1][j]&1){
						num[(i+1)&1][j^x]+=num[i&1][j]/2+1;
						num[(i+1)&1][j]+=num[i&1][j]/2;
						odd=false;
					}
					else{
						num[(i+1)&1][j^x]+=num[i&1][j]/2;
						num[(i+1)&1][j]+=num[i&1][j]/=2;
						odd=true;
					}
				}
				else{
					if(num[i&1][j]&1){
						num[(i+1)&1][j^x]+=num[i&1][j]/2;
						num[(i+1)&1][j]+=num[i&1][j]/2+1;
						odd=true;
					}
					else{
						num[(i+1)&1][j^x]+=num[i&1][j]/2;
						num[(i+1)&1][j]+=num[i&1][j]/2;
						odd=false;
					}
				}
					
			}
		}
		printf("\n");
	}
	int max_ans=-1;
	int min_ans=0x3f3f3f3f;
	for(int i=0;i<2050;i++){
		if(num[k&1][i]){
			max_ans=max(max_ans, i);
			min_ans=min(min_ans, i);
		}
	}
	printf("%d %d\n", max_ans, min_ans);
	return 0;
}

