// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 03월 02일 15시 35분 32초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[200000];
int b[200000];
pair<int, int> arr[200000];
int main(){
	scanf("%d%d", &n, &k);
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);
	for(int i=0;i<n;i++)
		scanf("%d", &b[i]);
	for(int i=0;i<n;i++)
		arr[i]={a[i]-b[i], i};
	sort(arr, arr+n);
	int ans=0;
	for(int i=0;i<k;i++)
		ans+=a[arr[i].second];
	for(int i=k;i<n;i++){
		if(arr[i].first<0)
			ans+=a[arr[i].second];
		else
			ans+=b[arr[i].second];
	}
	printf("%d\n", ans);

	return 0;
}

