// =====================================================================================
// 
//       Filename:  2872.cpp
//        Created:  2017년 08월 29일 01시 45분 38초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[300000];
int chk[300005];
bool possi(int x){
	memset(chk, 0, sizeof(chk));
	for(int i=1;i<=x;i++)
		chk[i]=1;
	int now=x+1;
	for(int i=0;i<n;i++){
		if(chk[arr[i]])
			continue;
		if(now!=arr[i])
			return false;
		now++;
	}
	return true;
}
int main(){
	scanf("%d", &n);
	int idx=-1;
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	int le, ri, mid, ans;
	le=0;
	ri=n;
	ans=-1;
	while(le<=ri){
		mid=(le+ri)/2;
		if(possi(mid)){
			ans=mid;
			ri=mid-1;
		}
		else
			le=mid+1;
	}
	printf("%d\n", ans);
	return 0;
}

