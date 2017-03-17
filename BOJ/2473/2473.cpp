// =====================================================================================
// 
//       Filename:  2473.cpp
//        Created:  2017년 03월 17일 16시 16분 56초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll arr[5000];
vector<int> ans;
int main(){
	scanf("%lld", &n);
	for(int i=0;i<n;i++)
		scanf("%lld", &arr[i]);
	sort(arr, arr+n);
	ll ans1=0x3f3f3f3f3f3f3f3f;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			ll now = arr[i]+arr[j];
			int idx = lower_bound(arr, arr+n, -now)-arr;
			int tt;
			vector<int> temp(3);
			temp[0]=arr[i];
			temp[1]=arr[j];
			if(idx==n)
				idx--;
			tt=idx;
			while((tt==i||tt==j)&&tt>=0){
				tt--;
			}
			if(tt!=i&&tt!=j&&tt>=0){
				temp[2]=arr[tt];
				if(ans1>abs(now+arr[tt])){
					ans1=abs(now+arr[tt]);
					ans=temp;
				}
			}
			tt=idx;
			while((tt==i||tt==j)&&tt<n){
				tt++;
			}
			if(tt!=i&&tt!=j&&tt<n){
				temp[2]=arr[tt];
				if(ans1>abs(now+arr[tt])){
					ans1=abs(now+arr[tt]);
					ans=temp;
				}
			}
		}
	}
	sort(ans.begin(), ans.end());
	for(int i=0;i<ans.size();i++)
		printf("%d ", ans[i]);
	return 0;
}

