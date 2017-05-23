// =====================================================================================
// 
//       Filename:  1114.cpp
//        Created:  2017년 05월 23일 10시 46분 48초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int l, k, c;
int arr[10005];
bool possi(int x){
	int cnt=0;
	int st=0;
	if(arr[0]-0>x)
		return false;
	for(int i=0;i<k;i++){
		if(arr[i+1]-st<=x)
			continue;
		else{
			cnt++;
			st=arr[i];
			if(arr[i+1]-st>x)
				return false;
		}
	}
	return cnt<=c;
}
int main(){
	scanf("%d%d%d", &l, &k, &c);
	for(int i=0;i<k;i++)
		scanf("%d", &arr[i]);
	sort(arr, arr+k);
	arr[k]=l;
	int le, ri, mid, ans;
	le=0;
	ri=l;
	while(le<=ri){
		mid=(le+ri)/2;
		if(possi(mid)){
			ans=mid;
			ri=mid-1;
		}
		else
			le=mid+1;
	}
	int idx=0;
	int st=l;
	int cnt=0;
	for(int i=k;i>0;i--){
		if(st-arr[i-1]<=ans)
			continue;
		else{
			cnt++;
			if(cnt==c)
				idx=i;
			st=arr[i];
		}
	}
	printf("%d %d\n", ans, arr[idx]);
	return 0;
}

