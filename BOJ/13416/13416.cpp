// =====================================================================================
// 
//       Filename:  13416.cpp
//        Created:  2017년 03월 26일 21시 02분 46초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int arr[1000][3];
int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		scanf("%d", &n);
		for(int i=0;i<n;i++)
			scanf("%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2]);
		ll ans=0;
		for(int i=0;i<n;i++){
			ans+=max(0, *max_element(arr[i], arr[i]+3));
		}
		printf("%lld\n", ans);
	}
	return 0;
}

