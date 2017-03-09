// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 03월 09일 16시 06분 35초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100000];
int g[100000];
int h[100000];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	bool flag=false;
	int now=0;
	for(int i=0;i<n;i++){
		if(arr[i]<now)
			flag=true;
		now=max(now, arr[i]);
	}
	if(flag){
		printf("-1\n");
		return 0;
	}
	int st=1;
	for(int i=0;i<n;i++){
		if(i==n-1||arr[i]!=arr[i+1]){
			if(st<=arr[i]&&arr[i]<=(i+1)){
				st=i+2;
				continue;
			}
			flag=true;
		}
	}
	if(flag){
		printf("-1\n");
		return 0;
	}
	int m=0;
	for(int i=0;i<n;i++){
		g[i]=m+1;
		h[m]=arr[i];
		if(i==n-1||arr[i]!=arr[i+1])
			m++;
	}
	printf("%d\n", m);
	for(int i=0;i<n;i++)
		printf("%d ", g[i]);
	printf("\n");
	for(int i=0;i<m;i++)
		printf("%d ", h[i]);
	printf("\n");
	return 0;
}
