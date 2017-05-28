// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 05월 27일 18시 44분 36초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[5000];
int l[5001];
int r[5001];
int cache[5000];
int solve(int idx){
	if(idx==n)
		return 0;
	int &ret=cache[idx];
	if(ret!=-1)
		return ret;
	ret=solve(idx+1);
	int le=0x3f3f3f3f;
	int ri=-1;
	int x=0;
	vector<bool> trip(5001, 0);	
	for(int i=idx;i<n;i++){
		le=min(le, l[arr[i]]);
		ri=max(ri, r[arr[i]]);
		if(!trip[arr[i]]){
			x^=arr[i];
			trip[arr[i]]=true;
		}
		if(idx<=le&&ri<=i){
			ret=max(ret, solve(i+1)+x);
		}
	}
	return ret;
}
int main(){
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	memset(l, 0x3f, sizeof(l));
	memset(r, -1, sizeof(r));
	for(int i=0;i<n;i++){
		l[arr[i]]=min(l[arr[i]], i);
		r[arr[i]]=max(r[arr[i]], i);
	}
	printf("%d\n", solve(0));

	return 0;
}

