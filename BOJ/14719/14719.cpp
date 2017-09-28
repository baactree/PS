// =====================================================================================
// 
//       Filename:  14719.cpp
//        Created:  2017년 09월 28일 15시 40분 03초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int h, w;
int arr[500];
int le[500];
int ri[500];
int main(){
	scanf("%d%d", &h, &w);
	for(int i=0;i<w;i++)
		scanf("%d", &arr[i]);
	le[0]=arr[0];
	for(int i=1;i<w;i++)
		le[i]=max(le[i-1], arr[i]);
	ri[w-1]=arr[w-1];
	for(int i=w-2;i>=0;i--)
		ri[i]=max(ri[i+1], arr[i]);
	int ans=0;
	for(int i=0;i<w;i++){
		int now=min(le[i], ri[i]);
		ans+=now-arr[i];
	}
	printf("%d\n", ans);
	return 0;
}

