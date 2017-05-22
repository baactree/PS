// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 05월 23일 00시 15분 41초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int a, b, h, w, n;
int arr[100000];
vector<pair<int, int> > f;
int k;
int st;
bool trip[50];
bool flag;
int tree[400000];
int sz;
void update(int idx, int val){
	idx+=sz;
	while(idx){
		tree[idx]=max(tree[idx], val);
		idx/=2;
	}
}
int query(int a, int b){
	int ret=0;
	a+=sz;
	b+=sz;
	while(a<=b){
		if(a&1){
			ret=max(ret, tree[a]);
			a++;
		}
		if(!(b&1)){
			ret=max(ret, tree[b]);
			b--;
		}
		a/=2;
		b/=2;
	}
	return ret;
}
void solve(int idx){
	if(idx==k){
		int p, q;
		p=h;
		q=w;
		for(int i=st;i<k;i++)
			if(trip[i])
				p=min(100000ll, (long long)p*arr[i]);
			else
				q=min(100000ll, (long long)q*arr[i]);
		update(p, q);
		return;
	}
	solve(idx+1);
	trip[idx]=true;
	solve(idx+1);
	trip[idx]=false;
}
void solve2(int idx){
	if(idx==k){
		int p, q;
		p=q=1;
		for(int i=st;i<k;i++)
			if(trip[i])
				p=min(100000ll, (long long)p*arr[i]);
			else
				q=min(100000ll, (long long)q*arr[i]);
		int t=query((a+p-1)/p, 100000);
		if((long long)t*q>=b)
			flag=true;
		t=query((b+p-1)/p, 100000);
		if((long long)t*q>=a)
			flag=true;
		return;
	}
	solve2(idx+1);
	trip[idx]=true;
	solve2(idx+1);
	trip[idx]=false;
}
bool possi(int x){
	memset(tree, 0, sizeof(tree));
	st=0;
	k=x/2;
	solve(0);
	k=x;
	flag=false;
	st=x/2;
	solve2(x/2);
	return flag;
}
int main(){
	scanf("%d%d%d%d%d", &a, &b, &h, &w, &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	sort(arr, arr+n);
	reverse(arr, arr+n);
	int le, ri, mid, ans;
	sz=1;
	while(sz<100000)
		sz*=2;
	ans=-1;
	le=0;
	ri=min(40, n);
	while(le<=ri){
		mid=(le+ri)/2;
		if(possi(mid)){
			ans=mid;
			ri=mid-1;
		}
		else
			le=mid+1;
	}
	printf("%d\n", ans);
	return 0;
}

