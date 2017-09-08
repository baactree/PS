// =====================================================================================
// 
//       Filename:  A.cpp
//        Created:  2017년 09월 08일 04시 11분 15초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
pair<double, pair<int, int> > a[4];
long long n;
int main(){
	for(int i=0;i<4;i++){
		scanf("%d", &a[i].second.first);
		a[i].first=a[i].second.first;
	}
	cin>>n;
	n*=4;
	a[1].first/=2;
	a[2].first/=4;
	a[3].first/=8;
	a[0].second.second=1;
	a[1].second.second=2;
	a[2].second.second=4;
	a[3].second.second=8;
	sort(a, a+4);
	long long ans=0;
	for(int i=0;i<4;i++){
		if(n>=a[i].second.second){
			long long k=n/a[i].second.second;
			ans+=k*a[i].second.first;
			n%=a[i].second.second;
		}
	}
	cout<<ans<<endl;
	return 0;
}

