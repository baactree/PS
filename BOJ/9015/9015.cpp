// =====================================================================================
// 
//       Filename:  9015.cpp
//        Created:  2017년 04월 30일 20시 54분 10초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
pair<int, int> arr[3000];
int n;
int main(){
	int TestCase;
	scanf("%d", &TestCase);
	while(TestCase--){
		scanf("%d", &n);
		set<pair<int, int> > s;
		for(int i=0;i<n;i++){
			scanf("%d%d", &arr[i].first, &arr[i].second);
			s.insert({arr[i].first, arr[i].second});
		}
		sort(arr, arr+n);
		int ans=0;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++){
				int nx=arr[j].first+arr[j].second-arr[i].second;
				int ny=arr[j].second-(arr[j].first-arr[i].first);
				if(s.find({nx, ny})!=s.end()){
					int tx=arr[i].first+arr[j].second-arr[i].second;
					int ty=arr[i].second-(arr[j].first-arr[i].first);
					if(s.find({tx, ty})!=s.end()){
						int q=arr[i].first-arr[j].first;
						int p=arr[i].second-arr[j].second;
						ans=max(ans, q*q+p*p);
					}
				}
			}
		printf("%d\n", ans);
	}
	return 0;
}

