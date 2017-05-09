// =====================================================================================
// 
//       Filename:  2528.cpp
//        Created:  2017년 05월 08일 18시 38분 41초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, l;
pair<int, int> arr[3000];
bool possi(int x, int t){
	int le, ri, dir;
	dir=arr[x].second;
	if(dir){
		le=l-arr[x].first;
		ri=l;
	}
	else{
		le=0;
		ri=arr[x].first;
	}
	int t1;
	if(arr[x].first==l)
		t1=0;
	else
		t1=t%(2*(l-arr[x].first));
	while(t1){
		if(dir){
			int temp=min(le, t1);
			t1-=temp;
			le-=temp;
			ri-=temp;
		}
		else{
			int temp=min(t1, l-ri);
			t1-=temp;
			le+=temp;
			ri+=temp;
		}
		dir=1-dir;
	}
	int nle, nri, ndir;
	ndir=arr[x+1].second;
	if(ndir){
		nle=l-arr[x+1].first;
		nri=l;
	}
	else{
		nle=0;
		nri=arr[x+1].first;
	}
	int t2;
	if(arr[x+1].first==l)
		t2=0;
	else
		t2=t%(2*(l-arr[x+1].first));
	while(t2){
		if(ndir){
			int temp=min(nle, t2);
			t2-=temp;
			nle-=temp;
			nri-=temp;
		}
		else{
			int temp=min(t2, l-nri);
			t2-=temp;
			nle+=temp;
			nri+=temp;
		}
		ndir=1-ndir;
	}
	return !(ri<nle||le>nri);
}
int main(){
	scanf("%d%d", &n, &l);
	for(int i=0;i<n;i++)
		scanf("%d%d", &arr[i].first, &arr[i].second);
	int ans=0;
	for(int i=0;i+1<n;i++)
		for(int j=0;j<=l*2;j++)
			if(possi(i, ans+j)){
				ans+=j;
				break;
			}
	printf("%d\n", ans);
	return 0;
}

