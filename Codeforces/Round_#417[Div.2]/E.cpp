// =====================================================================================
// 
//       Filename:  E.cpp
//        Created:  2017년 06월 02일 00시 35분 19초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100005];
int cnt[10000005];
bool leaf[100005];
int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &arr[i]);
	for(int i=2;i<=n;i++){
		int p;
		scanf("%d", &p);
		leaf[p]=true;
	}
	int x=0;
	for(int i=1;i<=n;i++)
		if(!leaf[i])
			x^=arr[i];
		else
			cnt[arr[i]]++;
	long long ans=0;
	if(x==0){
		for(int i=1;i<=n;i++){
			if(!leaf[i]){
				x^=arr[i];
				if(x<=10000005)
					ans+=cnt[x];
				x^=arr[i];
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}

