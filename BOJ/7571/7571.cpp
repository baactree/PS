// =====================================================================================
// 
//       Filename:  7571.cpp
//        Created:  2017년 01월 19일 16시 53분 11초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int N, M;
pair<int, int> arr[100000];
vector<int> x;
vector<int> y;
int main(){
	scanf("%d%d", &N, &M);
	for(int i=0;i<M;i++){
		scanf("%d%d", &arr[i].first, &arr[i].second);
		x.push_back(arr[i].first);
		y.push_back(arr[i].second);
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	int ansx=x[M/2];
	int ansy=y[M/2];
	int ans=0;
	for(int i=0;i<M;i++)
		ans+=abs(ansx-arr[i].first)+abs(ansy-arr[i].second);
	printf("%d\n", ans);
	return 0;
}

