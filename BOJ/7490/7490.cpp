// =====================================================================================
// 
//       Filename:  7490.cpp
//        Created:  2017년 05월 22일 16시 59분 08초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int arr[20];
int n;
void solve(int idx){
	if(idx==n){
		int ret=0;
		int x=0;
		int r=1;
		for(int i=n;i>=1;i--){
			x+=r*i;
			if(arr[i-1]==0){
				r*=10;
			}
			else if(arr[i-1]==1){
				ret-=x;
				x=0;
				r=1;
			}
			else{
				ret+=x;
				x=0;
				r=1;
			}
		}

		if(ret==0){
			printf("1");
			for(int i=2;i<=n;i++){
				if(arr[i-1]==0){
					printf("%c", ' ');
				}
				else if(arr[i-1]==1){
					printf("%c", '-');
				}
				else{
					printf("%c", '+');
				}
				printf("%d", i);
			}
			printf("\n");
		}
		return;
	}
	solve(idx+1);
	arr[idx]=2;
	solve(idx+1);
	arr[idx]=1;
	solve(idx+1);
	arr[idx]=0;
}
int main(){
	arr[0]=2;
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		scanf("%d", &n);
		solve(1);
		printf("\n");
	}
	return 0;
}

