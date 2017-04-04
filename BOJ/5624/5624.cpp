// =====================================================================================
// 
//       Filename:  5624.cpp
//        Created:  2017년 04월 04일 17시 59분 10초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int arr[5000];
bool check[400001];
const int shift=200000;
int n;
int main(){
	scanf("%d", &n);
	int ans=0;
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
		bool flag=false;
		for(int j=0;j<i;j++){
			if(check[arr[i]-arr[j]+shift])
				flag=true;
		}
		ans+=flag;
		for(int j=0;j<=i;j++)
			check[arr[i]+arr[j]+shift]=true;
	}
	printf("%d\n", ans);
	return 0;
}

