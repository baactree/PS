// =====================================================================================
// 
//       Filename:  2303.cpp
//        Created:  2017년 03월 03일 12시 59분 41초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1000][5];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		for(int j=0;j<5;j++)
			scanf("%d", &arr[i][j]);
	int max_val=-1;
	int ans;
	for(int i=0;i<n;i++){
		for(int j=0;j<5;j++)
			for(int k=j+1;k<5;k++)
				for(int p=k+1;p<5;p++){
					int temp=(arr[i][j]+arr[i][k]+arr[i][p])%10;
					if(temp>=max_val){
						max_val=temp;
						ans=i+1;
					}
				}
	}
	printf("%d\n", ans);
	return 0;
}

