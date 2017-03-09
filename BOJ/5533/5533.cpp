// =====================================================================================
// 
//       Filename:  5533.cpp
//        Created:  2017년 03월 09일 20시 13분 44초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int arr[200][3];
int n;
int score[200];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++)
			scanf("%d", &arr[i][j]);
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<n;j++){
			int now=arr[j][i];
			bool flag=false;
			for(int k=0;k<n;k++){
				if(k==j)
					continue;
				if(now==arr[k][i])
					flag=true;
			}
			if(!flag)
				score[j]+=now;
		}
	}
	for(int i=0;i<n;i++)
		printf("%d\n", score[i]);

	return 0;
}

