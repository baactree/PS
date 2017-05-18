// =====================================================================================
// 
//       Filename:  10424.cpp
//        Created:  2017년 05월 19일 00시 18분 31초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100000];
int tree[100005];
int b[100000];
int c[100000];
void update(int idx, int val){
	while(idx<100005){
		tree[idx]+=val;
		idx+=idx&(-idx);
	}
}
int query(int idx){
	int ret=0;
	while(idx){
		ret+=tree[idx];
		idx-=idx&(-idx);
	}
	return ret;
}
int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		int in;
		scanf("%d", &in);
		arr[in-1]=i;
	}
	for(int i=0;i<n;i++){
		b[i]=i-query(arr[i]);
		update(arr[i], 1);
	}
	memset(tree, 0, sizeof(tree));
	for(int i=n-1;i>=0;i--){
		c[i]=query(arr[i]);
		update(arr[i], 1);
	}
	for(int i=0;i<n;i++)
		printf("%d\n", b[i]-c[i]);
	return 0;
}

