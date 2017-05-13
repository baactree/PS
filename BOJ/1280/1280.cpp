// =====================================================================================
// 
//       Filename:  1280.cpp
//        Created:  2017년 05월 12일 14시 11분 29초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
long long tree[200005];
long long itree[200005];
const int mod=1000000007;
void update_idx(int idx, int val){
	idx++;
	while(idx<200005){
		itree[idx]+=val;
		idx+=idx&(-idx);
	}
}
int query_idx(int idx){
	idx++;
	int ret=0;
	while(idx){
		ret+=itree[idx];
		idx-=idx&(-idx);
	}
	return ret;
}
void update_tree(int idx, int val){
	idx++;
	while(idx<200005){
		tree[idx]+=val;
		idx+=idx&(-idx);
	}
}
long long query_tree(int idx){
	idx++;
	long long ret=0;
	while(idx){
		ret+=tree[idx];
		idx-=idx&(-idx);
	}
	return ret;
}
int main(){
	scanf("%d", &n);
	int ans=1;
	for(int i=0;i<n;i++){
		long long in;
		scanf("%lld", &in);
		int left=query_idx(in);
		int right=i-left;
		long long right_now=(query_tree(200000)-query_tree(in))-(in*right);
		long long left_now=left*in-query_tree(in);
		long long now=(left_now+right_now)%mod;
		if(i!=0)
			ans=(ans*now)%mod;
		update_idx(in, 1);
		update_tree(in, in);
	}
	printf("%d\n", ans);
	return 0;
}

