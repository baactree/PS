// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 06월 01일 23시 50분 20초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, s;
int arr[100000];
long long temp[1000000];
long long sum;
bool possi(int x){
	for(int i=0;i<n;i++)
		temp[i]=(long long)x*(i+1)+arr[i];
	sort(temp, temp+n);
	sum=0;
	for(int i=0;i<x;i++)
		sum+=temp[i];
	return sum<=s;
}
int main(){
	scanf("%d%d", &n, &s);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	int le, ri, mid, ans;
	int anss;
	anss=0;
	ans=0;
	le=1;
	ri=n;
	while(le<=ri){
		mid=(le+ri)/2;
		if(possi(mid)){
			ans=mid;
			anss=sum;
			le=mid+1;
		}
		else
			ri=mid-1;
	}
	printf("%d %d\n", ans, anss);
	return 0;
}

