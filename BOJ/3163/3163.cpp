// =====================================================================================
// 
//       Filename:  3163.cpp
//        Created:  2017년 04월 01일 18시 07분 24초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, L, k;
pair<int, int> arr[100000];
pair<int, int> temp[100000];
int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		scanf("%d%d%d", &n, &L, &k);
		for(int i=0;i<n;i++){
			scanf("%d%d", &arr[i].first, &arr[i].second);
			temp[i]=arr[i];
			if(arr[i].second>0)
				arr[i].first=L-arr[i].first;
			
		}
		sort(arr, arr+n);
		vector<pair<int, int>> ans;
		ans.push_back(arr[k-1]);
		bool flag=false;
		if(k!=n&&arr[k-1].first==arr[k].first)
			ans.push_back(arr[k]);
		if(k!=1&&arr[k-2].first==arr[k-1].first){
			flag=true;
			ans.push_back(arr[k-2]);
		}
		vector<int> g;
		for(int i=0;i<ans.size();i++){
			pair<int, int> now = ans[i];
			if(now.second>0){
				int loc=L-now.first;
				int cnt=0;
				for(int i=0;i<n;i++){
					if(temp[i].second>0&&temp[i].first>loc)
						cnt++;
				}
				g.push_back(temp[n-1-cnt].second);
			}
			else{
				int loc=now.first;
				int cnt=0;
				for(int i=0;i<n;i++){
					if(temp[i].second<0&&temp[i].first<loc)
						cnt++;
				}
				g.push_back(temp[cnt].second);
			}
		}
		printf("%d\n", flag?*max_element(g.begin(), g.end()):*min_element(g.begin(), g.end()));
	}
	return 0;
}

