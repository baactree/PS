// =====================================================================================
// 
//       Filename:  1849.cpp
//        Created:  2017년 04월 08일 12시 01분 50초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100001];
int tree[100005];
int ans[100001];
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
		scanf("%d", &arr[i]);
		update(i, 1);
	}
	for(int i=1;i<=n;i++){
		int now=arr[i]+1;
		int le, ri, mid, idx;
		le=1, ri=n;
		while(le<=ri){
			mid=(le+ri)/2;
			if(query(mid)>=now){
				idx=mid;
				ri=mid-1;
			}
			else
				le=mid+1;
		}
		ans[idx]=i;
		update(idx, -1);
	}
	for(int i=1;i<=n;i++)
		printf("%d\n", ans[i]);
	return 0;
}

