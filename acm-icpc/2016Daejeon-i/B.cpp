// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 09월 17일 18시 57분 40초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n;
pii arr[5005];
pii pivot;
int back[5005];
int dist(pii a, pii b){
	int x=a.first-b.first;
	int y=a.second-b.second;
	return x*x+y*y;
}
bool cmp(pii a, pii b){
	return dist(pivot, a)<dist(pivot, b);
}
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d%d", &arr[i].first, &arr[i].second);
	int len=-1;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++){
			int d=dist(arr[i], arr[j]);
			if(d>len){
				len=d;
				pivot=arr[i];
			}
		}
	sort(arr, arr+n, cmp);
	double ans=2e9;
	for(int i=n-2;i>=0;i--){
		back[i]=back[i+1];
		for(int j=i+1;j<n;j++)
			back[i]=max(back[i], dist(arr[i], arr[j]));
	}
	int max_value=0;
	for(int i=0;i+1<n;i++){
		for(int j=0;j<i;j++)
			max_value=max(max_value, dist(arr[j], arr[i]));
		ans=min(ans, sqrt(max_value)+sqrt(back[i+1]));
	}
	printf("%.10lf\n", ans);
	return 0;
}

