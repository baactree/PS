// =====================================================================================
// 
//       Filename:  2569.cpp
//        Created:  2017년 04월 23일 17시 14분 19초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> arr[1000];
bool trip[1000];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i].first);
		arr[i].second=i;
	}
	int ans=0;
	sort(arr, arr+n);
	for(int i=0;i<n;i++){
		if(!trip[i]){
			vector<int> cycle;
			int now=i;
			int min_temp=0x3f3f3f3f;
			int sum=0;
			while(!trip[now]){
				trip[now]=true;
				cycle.push_back(now);
				min_temp=min(min_temp, arr[now].first);
				sum+=arr[now].first;
				now=arr[now].second;
			}
			if(cycle.size()==1)
				continue;
			ans+=min((cycle.size()-2)*(min_temp)+sum, (cycle.size()+1)*arr[0].first+sum+min_temp);
		}
	}

	printf("%d\n", ans);
	return 0;
}

