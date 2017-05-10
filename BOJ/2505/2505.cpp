// =====================================================================================
// 
//       Filename:  2505.cpp
//        Created:  2017년 05월 01일 15시 18분 02초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int arr[10005];
int temp[10005];
vector<pair<int, int> >  ans;
int n;
int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d", &arr[i]);
		temp[i]=arr[i];
	}
	for(int i=1;i<=n;i++){
		if(temp[i]!=i){
			int st=i;
			int fi=i;
			for(int j=i+1;j<=n;j++)
				if(temp[j]==i){
					fi=j;
					break;
				}
			ans.push_back({st, fi});
			reverse(temp+st, temp+fi+1);
		}
	}
	if(ans.size()<=2){
		while(ans.size()<2)
			ans.push_back({1, 1});
		for(int i=0;i<ans.size();i++)
			printf("%d %d\n", ans[i].first, ans[i].second);
		return 0;
	}
	ans.clear();
	for(int i=1;i<=n;i++)
		temp[i]=arr[i];
	for(int i=n;i>=1;i--){
		if(temp[i]!=i){
			int fi=i;
			int st=i;
			for(int j=i-1;j>=1;j--){
				if(temp[j]==i){
					st=j;
					break;
				}
			}
			ans.push_back({st, fi});
			reverse(temp+st, temp+fi+1);
		}
	}
	if(ans.size()<=2){
		while(ans.size()<2)
			ans.push_back({1, 1});
		for(int i=0;i<ans.size();i++)
			printf("%d %d\n", ans[i].first, ans[i].second);
		return 0;
	}
	return 0;
}

