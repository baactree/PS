// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 04월 25일 22시 34분 44초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m, k;
bool hole[1000001];
bool bone[1000001];
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0;i<m;i++){
		int in;
		scanf("%d", &in);
		hole[in]=true;
	}
	if(hole[1]){
		printf("1\n");
		return 0;
	}
	bone[1]=true;
	int ans;
	for(int i=0;i<k;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		swap(bone[a], bone[b]);
		if(hole[a]&&bone[a]){
			bone[a]=false;
			ans=a;
		}
		if(hole[b]&&bone[b]){
			bone[b]=false;
			ans=b;
		}
	}
	for(int i=1;i<=n;i++)
		if(bone[i])
			ans=i;
	printf("%d\n", ans);
	
	return 0;
}

