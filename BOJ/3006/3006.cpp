// =====================================================================================
// 
//       Filename:  3006.cpp
//        Created:  2017년 06월 14일 01시 14분 25초
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
int k[100005];
void update(int idx, int val){
	idx++;
	while(idx<100005){
		tree[idx]+=val;
		idx+=idx&(-idx);
	}
}
int query(int idx){
	int ret=0;
	idx++;
	while(idx){
		ret+=tree[idx];
		idx-=idx&(-idx);
	}
	return ret;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
		k[arr[i]]=i;
	}
	int p=0;
	for(int i=0;i<n;i++){
		if(i&1){
			int t=k[n-p];
			printf("%d\n", abs(n-1-p-(t+query(t))));
			update(t, -1);
			p++;
		}
		else{
			int t=k[p+1];
			printf("%d\n", abs(p-(t+query(t))));
			update(0, 1);
			update(t, -1);
		}
	}
	return 0;
}

