// =====================================================================================
// 
//       Filename:  5676.cpp
//        Created:  2017년 04월 03일 10시 44분 41초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
vector<int> tree;
int sz;
int n, k;
vector<int> arr;
void update(int idx, int val){
	idx+=sz/2;
	tree[idx]=val;
	idx/=2;
	while(idx>0){
		tree[idx]=tree[idx*2]*tree[idx*2+1];
		idx/=2;
	}
}
int query(int a, int b){
	a+=sz/2;
	b+=sz/2;
	int ret=1;
	while(a<=b){
		if(a&1){
			ret*=tree[a];
			a++;
		}
		if(!(b&1)){
			ret*=tree[b];
			b--;
		}
		a/=2;
		b/=2;
	}
	return ret;
}
int main(){
	while(scanf("%d%d", &n, &k)!=EOF){
		sz=1;
		while(sz<n)
			sz*=2;
		sz*=2;
		tree=vector<int>(sz+1, 1);
		arr=vector<int>(n);
		for(int i=0;i<n;i++){
			scanf("%d", &arr[i]);
			if(arr[i]>0)
				arr[i]=1;
			else if(arr[i]<0)
				arr[i]=-1;
			update(i, arr[i]);
		}
		for(int i=0;i<k;i++){
			char order[10];
			int a, b;
			scanf("%s%d%d", order, &a, &b);
			if(order[0]=='C'){
				if(b>0)
					b=1;
				else if(b<0)
					b=-1;
				update(a-1, arr[a-1]);
				arr[a-1]=b;
				update(a-1, arr[a-1]);
			}
			else{
				int ans=query(a-1, b-1);
				if(ans==0){
					printf("0");
				}
				else if(ans==1){
					printf("+");
				}
				else
					printf("-");
			}
		}
		printf("\n");
	}
	return 0;
}

