// =====================================================================================
// 
//       Filename:  13303.cpp
//        Created:  2017년 05월 31일 01시 34분 28초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
struct Node{
	int x, yl, yh;
	bool operator < (const Node &rhs)const{
		return x<rhs.x;
	}
};
int n;
int st, fi;
Node arr[100000];
map<int, int> mp;
const int inf=0x3f3f3f3f;
int main(){
	scanf("%d", &n);
	scanf("%d%d", &st, &fi);
	for(int i=0;i<n;i++)
		scanf("%d%d%d", &arr[i].x, &arr[i].yl, &arr[i].yh);
	sort(arr, arr+n);
	mp[st]=0;
	for(int i=0;i<n;i++){
		auto st=mp.lower_bound(arr[i].yl);
		auto ed=mp.upper_bound(arr[i].yh);
		int yld=inf;
		int yhd=inf;
		for(auto it=st;it!=ed;it++){
			yld=min(yld, it->first-arr[i].yl+it->second);
			yhd=min(yhd, arr[i].yh-it->first+it->second);
		}
		mp.erase(st, ed);
		mp[arr[i].yl]=yld;
		mp[arr[i].yh]=yhd;
	}
	int ans=inf;
	vector<int> anss;
	for(auto it=mp.begin();it!=mp.end();it++){
		int y=it->first;
		int cost=it->second;
		if(cost<ans){
			anss.clear();
			ans=cost;
			anss.push_back(y);
		}
		else if(cost==ans)
			anss.push_back(y);
	}
	sort(anss.begin(), anss.end());
	printf("%d\n", ans+fi);
	printf("%d ", anss.size());
	for(int i=0;i<anss.size();i++)
		printf("%d ", anss[i]);
	printf("\n");
	return 0;
}

