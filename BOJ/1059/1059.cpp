// =====================================================================================
// 
//       Filename:  1059.cpp
//        Created:  2017년 04월 13일 18시 44분 28초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int l, n;
int tree[1005];
void update(int idx, int val){
	while(idx<1005){
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
	scanf("%d", &l);
	for(int i=0;i<l;i++){
		int in;
		scanf("%d", &in);
		update(in, 1);
	}
	scanf("%d", &n);
	int ans=0;
	for(int i=1;i<=1000;i++)
		for(int j=i+1;j<=1000;j++){
			if(i<=n&&n<=j){
				if(query(j)-query(i-1)==0){
					ans++;
				}
			}
		}
	printf("%d\n", ans);
	return 0;
}

