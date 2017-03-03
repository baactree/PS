// =====================================================================================
// 
//       Filename:  E.cpp
//        Created:  2017년 02월 24일 20시 32분 08초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
struct V{
	int a, b, h;
	bool operator <(const V &rhs)const{
		if(b==rhs.b)
			return a>rhs.a;
		return b>rhs.b;
	}
};
V arr[100000];
vector<int> aidx;
long long dp[200005];
void update(int idx, long long val){
	idx++;
	while(idx<200005){
		dp[idx]=max(dp[idx], val);
		idx+=idx&(-idx);
	}
}
long long query(int idx){
	idx++;
	long long ret=0;
	while(idx){
		ret=max(ret, dp[idx]);
		idx-=idx&(-idx);
	}
	return ret;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d", &arr[i].a, &arr[i].b, &arr[i].h);
		aidx.push_back(arr[i].a);
		aidx.push_back(arr[i].b-1);
	}
	sort(aidx.begin(), aidx.end());
	aidx.erase(unique(aidx.begin(), aidx.end()), aidx.end());
	sort(arr, arr+n);
	for(int i=0;i<n;i++){
		update(lower_bound(aidx.begin(), aidx.end(), arr[i].a)-aidx.begin(), query(lower_bound(aidx.begin(), aidx.end(), arr[i].b-1)-aidx.begin())+arr[i].h);
	}
	printf("%lld\n", query(aidx.size()-1));
	return 0;
}

