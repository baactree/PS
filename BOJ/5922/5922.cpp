// =====================================================================================
// 
//       Filename:  5922.cpp
//        Created:  2017년 09월 11일 23시 59분 58초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, x;
int arr[100000];
typedef long long ll;
ll tree[200005];
void update(int idx, int val){
	idx+=100000;
	while(idx<200005){
		tree[idx]+=val;
		idx+=idx&(-idx);
	}
}
ll query(int idx){
	ll ret=0;
	idx+=100000;
	while(idx){
		ret+=tree[idx];
		idx-=idx&(-idx);
	}
	return ret;
}
int main(){
	scanf("%d%d", &n, &x);
	int shift=0;
	ll ans=0;
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
		if(arr[i]>=x)
			arr[i]=1;
		else
			arr[i]=-1;
		update(shift, 1);
		shift-=arr[i];	
		ans+=(i+1-query(shift-1));
	}
	cout<<ans<<endl;
	return 0;
}

