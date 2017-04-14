// =====================================================================================
// 
//       Filename:  1205.cpp
//        Created:  2017년 04월 14일 11시 35분 38초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, s, p;
int arr[50];
int main(){
	scanf("%d%d%d", &n, &s, &p);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	bool flag=false;
	for(int i=0;i<n;i++){
		if(s>arr[i])
			flag=true;
	}
	if(n==p&&!flag){
		printf("-1\n");
		return 0;
	}
	int cnt=1;
	for(int i=0;i<n;i++){
		if(arr[i]<=s){
			printf("%d\n", cnt);
			return 0;
		}
		cnt++;
	}
	printf("%d\n", n+1);
	return 0;
}

