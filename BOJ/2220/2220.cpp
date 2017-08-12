// =====================================================================================
// 
//       Filename:  2220.cpp
//        Created:  2017년 08월 11일 21시 44분 23초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int main(){
	int n;
	scanf("%d", &n);
	arr[1]=1;
	for(int i=2;i<=n;i++){
		int idx=i-1;
		while(idx>1){
			arr[idx]=arr[idx/2];
			idx>>=1;
		}
		arr[1]=i;
		arr[i]=1;
	}
	for(int i=1;i<=n;i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}

