// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 04월 30일 18시 59분 14초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[50];
int u;
typedef long long ll;
bool possi(int x){
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=max(0, x-arr[i]);
	return sum<=u;
}
double f(int x){
	double ret=0;
	for(int i=0;i<n;i++){
		int now=max(x, arr[i]);
		ret+=log10(now*0.0001);
	}
	return ret;
}
int main(){
	freopen("C-small-1.in", "r", stdin);
	freopen("C-small-1.out", "w", stdout);
	int TestCase;
	scanf("%d", &TestCase);
	for(int tc=1;tc<=TestCase;tc++){
		scanf("%d%d", &n, &k);
		double temp;
		scanf("%lf", &temp);
		u=temp*10000+1e-9;
		for(int i=0;i<n;i++){
			scanf("%lf", &temp);
			arr[i]=temp*10000+1e-9;
		}
		double ans=-999999999;
		for(int i=0;i<=10000;i++){
			if(possi(i))
				ans=max(ans, f(i));
			else{
				break;
			}
		}
		printf("Case #%d: %.6f\n", tc, pow(10, ans)+1e-9);

	}
	return 0;
}

