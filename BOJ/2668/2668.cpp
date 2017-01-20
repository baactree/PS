// =====================================================================================
// 
//       Filename:  2668.cpp
//        Created:  2017년 01월 20일 18시 04분 09초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int arr[101];
int N;
int trip[101];
bool ans[101];
void dfs(int n){
	if(trip[n]==2)
		return;
	trip[n]++;
	dfs(arr[n]);
}
int main(){
	scanf("%d", &N);
	for(int i=0;i<N;i++)
		scanf("%d", &arr[i+1]);
	for(int i=1;i<=N;i++){
		memset(trip, 0, sizeof(trip));
		dfs(i);
		for(int i=1;i<=N;i++)
			if(trip[i]==2)
				ans[i]=true;
	}
	int cnt=0;
	for(int i=1;i<=N;i++)
		if(ans[i])
			cnt++;
	printf("%d\n", cnt);
	for(int i=1;i<=N;i++)
		if(ans[i])
			printf("%d\n", i);
	return 0;
}

