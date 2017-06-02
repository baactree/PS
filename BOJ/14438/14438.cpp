// =====================================================================================
// 
//       Filename:  14438.cpp
//        Created:  2017년 06월 02일 12시 40분 40초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int tree[400005];
int sz;
void update(int idx, int val){
	idx+=sz;
	tree[idx]=val;
	idx/=2;
	while(idx){
		tree[idx]=min(tree[idx*2], tree[idx*2+1]);
		idx/=2;
	}
}
int query(int a, int b){
	a+=sz;
	b+=sz;
	int ret=0x3f3f3f3f;
	while(a<=b){
		if(a&1){
			ret=min(ret, tree[a]);
			a++;
		}
		if(!(b&1)){
			ret=min(ret, tree[b]);
			b--;
		}
		a/=2;
		b/=2;
	}
	return ret;
}
int main(){
	scanf("%d", &n);
	memset(tree, 0x3f, sizeof(tree));
	sz=1;
	while(sz<n)
		sz*=2;
	for(int i=1;i<=n;i++){
		int in;
		scanf("%d", &in);
		update(i, in);
	}
	scanf("%d", &m);
	for(int i=0;i<m;i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if(a==1){
			update(b, c);
		}
		else{
			printf("%d\n", query(b, c));
		}
	}
	return 0;
}

