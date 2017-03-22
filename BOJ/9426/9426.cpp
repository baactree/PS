// =====================================================================================
// 
//       Filename:  9426.cpp
//        Created:  2017년 03월 22일 19시 04분 46초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
int cnt[70000];
int sz=sqrt(70000);
int sq[1000];
int query(int x){
	int ret=0;
	int sum=0;
	while(true){
		if(sum+sq[ret]>=x)
			break;
		else
			sum+=sq[ret++];
	}
	x-=sum;
	sum=0;
	for(int i=sz*ret;;i++)
		if(sum+cnt[i]>=x)
			return i;
		else
			sum+=cnt[i];
	return 0;
}
int main(){
	queue<int> q;
	scanf("%d%d", &n, &k);
	long long ans=0;
	for(int i=0;i<n;i++){
		if(i>=k){
			int now=q.front();
			q.pop();
			cnt[now]--;
			sq[now/sz]--;
		}
		int in;
		scanf("%d", &in);
		q.push(in);
		cnt[in]++;
		sq[in/sz]++;
		if(i<k-1)
			continue;
		int x=min(i+1, k);
		ans+=query((x+1)/2);
	}
	printf("%lld\n", ans);
	return 0;
}

