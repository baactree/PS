// =====================================================================================
// 
//       Filename:  9006.cpp
//        Created:  2017년 09월 30일 16시 57분 10초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1000005], b[1000005];
typedef long long ll;
ll sa[1000005], sb[1000005];
typedef unsigned long long llu;
int main(){
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		scanf("%d%d", &n, &m);
		vector<int> vec;
		for(int i=1;i<=n;i++){
			scanf("%d", &a[i]);
			vec.push_back(a[i]);
		}
		for(int i=1;i<=m;i++){
			scanf("%d", &b[i]);
			vec.push_back(b[i]);
		}
		sort(a+1, a+n+1);
		sort(b+1, b+m+1);
		sort(vec.begin(), vec.end());
		for(int i=1;i<=n;i++)
			sa[i]=sa[i-1]+a[i];
		for(int i=1;i<=m;i++)
			sb[i]=sb[i-1]+b[i];
		llu ans=10000000000000000005;
		int h=0;
		for(int i=0;i<vec.size();i++){
			llu now=0;
			int idx=upper_bound(a+1, a+n+1, vec[i])-(a+1);
			ll nh=vec[i];
			now+=(nh*idx-sa[idx])*(llu)m;
			now+=((sa[n]-sa[idx])-nh*(n-idx))*(llu)m;
			idx=upper_bound(b+1, b+m+1, vec[i])-(b+1);
			now+=(nh*idx-sb[idx])*(llu)n;
			now+=((sb[m]-sb[idx])-nh*(m-idx))*(llu)n;
			if(ans>now){
				ans=now;
				h=vec[i];
			}
		}
		printf("%d.0\n", h);
	}
	return 0;
}

