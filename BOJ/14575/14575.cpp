// =====================================================================================
// 
//       Filename:  14575.cpp
//        Created:  2017년 09월 13일 18시 49분 09초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, t;
int l[1000], r[1000];
bool possi(int x){
	long long sum=0;
	for(int i=0;i<n;i++){
		sum+=min(x, r[i]);
	}
	return sum>=t;
}
int main(){
	scanf("%d%d", &n, &t);
	int max_value=-1;
	long long sum=0;
	for(int i=0;i<n;i++){
		scanf("%d%d", &l[i], &r[i]);
		max_value=max(max_value, l[i]);	
		sum+=l[i];
	}
	if(sum>t)
		return !printf("-1\n");
	int le, ri, mid, ans;
	le=max_value;
	ri=1e6;
	ans=-1;
	while(le<=ri){
		int mid=(le+ri)/2;
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

