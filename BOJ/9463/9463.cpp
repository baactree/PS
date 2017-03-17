// =====================================================================================
// 
//       Filename:  9463.cpp
//        Created:  2017년 03월 15일 21시 45분 49초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int a[100001];
int b[100000];
int tree[100005];
void update(int x){
	x++;
	while(x<100005){
		tree[x]+=1;
		x+=x&(-x);
	}
}
long long query(int x){
	long long ret=0;
	x++;
	while(x>0){
		ret+=tree[x];
		x-=x&(-x);
	}
	return ret;
}
int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		memset(tree, 0, sizeof(tree));
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			int in;
			scanf("%d", &in);
			a[in]=i;
		}
		for(int i=0;i<n;i++){
			int in;
			scanf("%d", &in);
			b[i]=a[in];
		}
		long long ans=0;
		for(int i=0;i<n;i++){
			ans+=i-query(b[i]);
			update(b[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

