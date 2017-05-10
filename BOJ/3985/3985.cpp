// =====================================================================================
// 
//       Filename:  3985.cpp
//        Created:  2017년 05월 09일 15시 00분 28초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int n, l;
int ans1, ans2;
int idx1, idx2;
int main(){
	memset(arr, -1, sizeof(arr));
	ans1=ans2=-1;
	scanf("%d%d", &l, &n);
	for(int i=0;i<n;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		if(ans1<b-a+1){
			ans1=b-a+1;
			idx1=i+1;
		}
		int cnt=0;
		for(int j=a;j<=b;j++){
			if(arr[j]==-1){
				arr[j]=i;
				cnt++;
			}
		}
		if(ans2<cnt){
			ans2=cnt;
			idx2=i+1;
		}
	}
	printf("%d\n%d\n", idx1, idx2);
	return 0;
}

