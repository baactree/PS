// =====================================================================================
// 
//       Filename:  3653.cpp
//        Created:  2017년 03월 27일 21시 04분 37초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int loc[100001];
int tree[200005];
void update(int idx, int val){
	while(idx<200005){
		tree[idx]+=val;
		idx+=idx&(-idx);
	}
}
int query(int idx){
	int ret=0;
	while(idx>0){
		ret+=tree[idx];
		idx-=idx&(-idx);
	}
	return ret;
}
int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		memset(tree, 0, sizeof(tree));
		memset(loc, 0, sizeof(loc));
		scanf("%d%d", &n, &m);
		for(int i=1;i<=n;i++){
			loc[i]=i+m;
			update(i+m, 1);
		}
		for(int i=0;i<m;i++){
			int in;
			scanf("%d", &in);
			printf("%d ", query(loc[in])-1);
			update(loc[in], -1);
			loc[in]=m-i;
			update(loc[in], 1);
		}
	}
	return 0;
}

