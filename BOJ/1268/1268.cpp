// =====================================================================================
// 
//       Filename:  1268.cpp
//        Created:  2017년 04월 13일 18시 55분 14초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1000][5];
int cnt[1000];
int check[1000];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		for(int j=0;j<5;j++)
			scanf("%d", &arr[i][j]);
	for(int i=0;i<n;i++){
		memset(check, 0, sizeof(check));
		for(int j=0;j<5;j++)
			for(int k=0;k<n;k++){
				if(k==i)continue;
				if(arr[i][j]==arr[k][j]&&!check[k]){
					cnt[i]++;
					check[k]=true;
				}
			}
	}
	int max_val=-1;
	int ans;
	for(int i=0;i<n;i++){
		if(max_val<cnt[i]){
			max_val=cnt[i];
			ans=i+1;
		}
	}
	printf("%d\n",ans);
	return 0;
}

