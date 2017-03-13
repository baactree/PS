// =====================================================================================
// 
//       Filename:  1244.cpp
//        Created:  2017년 03월 13일 22시 54분 32초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[101];
int m;
void update(int sex, int x){
	if(sex==1){
		for(int i=x;i<=n;i+=x)
			arr[i]^=1;
		return;
	}
	int le, ri;
	le=ri=x;
	while(le>0&&ri<=n){
		if(arr[le]!=arr[ri])
			break;
		le--;
		ri++;
	}
	for(int i=le+1;i<ri;i++)
		arr[i]^=1;
}
int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &arr[i]);
	scanf("%d", &m);
	for(int i=0;i<m;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		update(a, b);
	}
	for(int i=1;i<=n;i++){
		printf("%d ", arr[i]);
		if(i%20==0)
			printf("\n");
	}
	return 0;
}

