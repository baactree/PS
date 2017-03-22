// =====================================================================================
// 
//       Filename:  1321.cpp
//        Created:  2017년 03월 22일 17시 54분 19초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[500000];
int sz;
int sq[1000];
int query(int x){
	int ret=0;
	int sum=0;
	while(true){
		if(sum+sq[ret]>=x){
			break;
		}
		else{
			sum+=sq[ret];
			ret++;
		}
	}
	x-=sum;
	sum=0;
	for(int i=sz*ret;;i++){
		if(sum+arr[i]>=x)
			return i+1;
		else{
			sum+=arr[i];
		}
	}
	return 0;
}
int main(){
	scanf("%d", &n);
	sz=sqrt(n);
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
		sq[i/sz]+=arr[i];
	}
	scanf("%d", &m);
	for(int i=0;i<m;i++){
		int a;
		scanf("%d", &a);
		if(a==1){
			int b, c;
			scanf("%d%d", &b, &c);
			b--;
			arr[b]+=c;
			sq[b/sz]+=c;
		}
		else{
			int b;
			scanf("%d", &b);
			printf("%d\n", query(b));
		}
	}
	return 0;
}

