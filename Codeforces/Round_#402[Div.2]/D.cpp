// =====================================================================================
// 
//       Filename:  D.cpp
//        Created:  2017년 03월 02일 15시 45분 01초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
string t, p;
int arr[200000];
bool possi(int x){
	string temp=t;
	for(int i=0;i<x;i++)
		temp[arr[i]-1]='_';
	int idx=0;
	for(int i=0;i<temp.size();i++){
		if(p[idx]==temp[i])
			idx++;
	}
	return idx==p.size();
}
int main(){
	cin>>t>>p;
	for(int i=0;i<t.size();i++)
		scanf("%d", &arr[i]);
	int le, ri, mid;
	le=0;
	ri=t.size();
	int ans;
	while(le<=ri){
		mid=(le+ri)/2;
		if(possi(mid)){
			ans=mid;
			le=mid+1;
		}
		else
			ri=mid-1;
	}
	printf("%d\n", ans);
	return 0;
}

