// =====================================================================================
// 
//       Filename:  9011.cpp
//        Created:  2017년 03월 15일 21시 16분 38초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100];
int ans[100];
bool check[101];
int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		memset(check, 0, sizeof(check));
		scanf("%d", &n);
		for(int i=0;i<n;i++)
			scanf("%d", &arr[i]);
		for(int i=n-1;i>=0;i--){
			int cnt=0;
			int idx;
			for(idx=1;idx<n;idx++){
				if(cnt==arr[i]&&!check[idx])
					break;
				if(!check[idx])
					cnt++;
			}
			if(cnt!=arr[i]||check[idx]){
				printf("IMPOSSIBLE\n");
				goto next;
			}
			ans[i]=idx;
			check[idx]=true;
		}
		for(int i=0;i<n;i++)
			printf("%d ", ans[i]);
		printf("\n");
next:;
	}
	return 0;
}

