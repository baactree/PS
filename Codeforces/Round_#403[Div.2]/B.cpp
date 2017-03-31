// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 03월 31일 16시 10분 40초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
double x[60000];
double v[60000];
bool possi(ll t){
	double le, ri;
	le=-1e18;
	ri=1e18;
	for(int i=0;i<n;i++){
		double nl=x[i]-v[i]*t;
		double nr=x[i]+v[i]*t;
		le=max(le, nl);
		ri=min(ri, nr);
		if(le>ri)
			return false;
	}
	return true;
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%lf", &x[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%lf", &v[i]);
		v[i]/=1e7;
	}
	ll le, ri, mid;
	ll ans;
	le=0;
	ri=1e18;
	while(ri>=le){
		mid=(le+ri)/2;
		if(possi(mid)){
			ans=mid;
			ri=mid-1;
		}
		else 
			le=mid+1;
	}
	printf("%.7lf\n",(double)ans/1e7 );
	return 0;
}
