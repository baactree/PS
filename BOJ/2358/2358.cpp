// =====================================================================================
// 
//       Filename:  2358.cpp
//        Created:  2017년 04월 09일 18시 21분 46초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
map<int, int> x;
map<int, int> y;
pair<int, int> arr[100000];
set<int> ansx;
set<int> ansy;
int n;
int main(){
	scanf("%d", &n);
	long long ans=0;
	for(int i=0;i<n;i++){
		scanf("%d%d", &arr[i].first, &arr[i].second);
		x[arr[i].first]++;
		y[arr[i].second]++;
	}
	for(int i=0;i<n;i++){
		if(x[arr[i].first]>1)
			ansx.insert(arr[i].first);
		if(y[arr[i].second]>1)
			ansy.insert(arr[i].second);
	}
	printf("%d\n", ansx.size()+ansy.size());

	return 0;
}

