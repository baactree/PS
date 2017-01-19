// =====================================================================================
// 
//       Filename:  2661.cpp
//        Created:  2017년 01월 19일 17시 14분 03초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int arr[80];
int N;
bool possi(int idx){
	for(int i=1;i<=idx/2;i++){
		for(int j=0;j<=idx-2*i;j++){
			bool flag=true;
			for(int k=0;k<i;k++){
				if(arr[j+k]!=arr[j+k+i])
					flag=false;
			}
			if(flag)
				return false;
		}
	}
	return true;
}
void solve(int idx){
	if(!possi(idx))
		return;
	if(idx==N){
		for(int i=0;i<N;i++)
			printf("%d", arr[i]);
		printf("\n");
		exit(0);
	}
	for(int i=0;i<3;i++){
		arr[idx]=i+1;
		solve(idx+1);
	}
}
int main(){
	scanf("%d", &N);
	solve(0);
	return 0;
}

