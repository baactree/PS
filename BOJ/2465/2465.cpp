// =====================================================================================
// 
//       Filename:  2465.cpp
//        Created:  2017년 05월 22일 17시 48분 01초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int tree[100005];
int n;
int arr[100000];
int s[100000];
vector<int> x;
void update(int idx, int val){
	idx++;
	while(idx<100005){
		tree[idx]+=val;
		idx+=(idx)&(-idx);
	}
}
int query(int idx){
	idx++;
	int ret=0;
	while(idx){
		ret+=tree[idx];
		idx-=idx&(-idx);
	}
	return ret;
}
int ans[100000];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
		x.push_back(arr[i]);
	}
	for(int i=0;i<n;i++)
		scanf("%d", &s[i]);
	sort(x.begin(), x.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	for(int i=0;i<n;i++){
		int idx=lower_bound(x.begin(), x.end(), arr[i])-x.begin();
		update(idx, 1);
	}
	for(int i=n-1;i>=0;i--){
		int le, ri, mid, idx;
		le=0;ri=n;
		while(le<=ri){
			mid=(le+ri)/2;
			if(query(mid)>s[i]){
				idx=mid;
				ri=mid-1;
			}
			else
				le=mid+1;
		}
		update(idx, -1);
		ans[i]=x[idx];
	}
	for(int i=0;i<n;i++)
		printf("%d\n", ans[i]);
	return 0;
}

