// =====================================================================================
// 
//       Filename:  1994.cpp
//        Created:  2017년 09월 20일 20시 51분 33초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> arr;
int cache[2005][2005];
int solve(int idx, int pre){
	int &ret=cache[idx][pre];
	if(ret!=-1)
		return ret;
	int d=arr[idx]-arr[pre];
	ret=1;
	int nidx=lower_bound(arr.begin(), arr.end(), arr[idx]+d)-arr.begin();
	if(nidx<arr.size()&&arr[nidx]==arr[idx]+d)
		ret=max(ret, solve(nidx, idx)+1);
	return ret;
}
int main(){
	scanf("%d", &n);
	map<int, int> mp;
	int ans=0;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d", &x);
		arr.push_back(x);
		ans=max(ans, ++mp[arr[i]]);
	}
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	memset(cache, -1, sizeof(cache));
	for(int i=0;i<arr.size();i++)
		for(int j=i+1;j<arr.size();j++){
			ans=max(ans, solve(j, i)+1);
		}
	printf("%d\n", ans);
	return 0;
}

