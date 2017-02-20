// =====================================================================================
// 
//       Filename:  2467.cpp
//        Created:  2017년 02월 20일 19시 22분 41초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int N;
int arr[100000];
int main(){
	scanf("%d", &N);
	for(int i=0;i<N;i++)
		scanf("%d", &arr[i]);
	int dist=2*1e9+5;
	pair<int, int> ans={0, 0};
	for(int i=0;i<N;i++){
		int le=lower_bound(arr, arr+N, -arr[i])-arr;
		for(int j=max(0, le-1);j<min(N, le+2);j++){
			if(j!=i){
				if(dist>abs(arr[i]+arr[j])){
					dist=abs(arr[i]+arr[j]);
					ans={arr[i], arr[j]};
				}
			}
		}
	}
	if(ans.first>ans.second)
		swap(ans.first, ans.second);
	printf("%d %d\n", ans.first, ans.second);
	return 0;
}

