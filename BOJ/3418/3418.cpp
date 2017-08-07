// =====================================================================================
// 
//       Filename:  3418.cpp
//        Created:  2017년 08월 07일 22시 41분 45초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[1000005];
int pre[1000005];
int tree[4000005];
int sz;
void update(int idx, int val){
	idx+=sz;
	while(idx){
		tree[idx]=max(tree[idx], val);
		idx/=2;
	}
}
int query(int a, int b){
	a+=sz;
	b+=sz;
	int ret=0;
	while(a<=b){
		if(a&1)
			ret=max(ret, tree[a++]);
		if(!(b&1))
			ret=max(ret, tree[b--]);
		a/=2;
		b/=2;
	}
	return ret;
}
int main(){
	while(true){
		scanf("%d%d", &n, &m);
		if(n==0&&m==0)
			break;
		sz=1;
		while(sz<=n)sz*=2;
		map<int, int> mp;
		memset(tree, 0, sizeof(tree));	
		for(int i=1;i<=n;i++){
			scanf("%d", &arr[i]);
			if(mp.count(arr[i])==0)
				pre[i]=0;
			else
				pre[i]=mp[arr[i]];
			update(i, pre[i]);
			mp[arr[i]]=i;
		}
		while(m--){
			int a, b;
			scanf("%d%d", &a, &b);
			int idx=query(a, b);
			if(a<=idx&&idx<=b)
				printf("%d\n", arr[idx]);
			else
				printf("OK\n");
		}
		printf("\n");
	}
	return 0;
}

