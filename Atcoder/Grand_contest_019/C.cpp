// =====================================================================================
// 
//       Filename:  C.cpp
//        Created:  2017년 09월 08일 04시 58분 41초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> arr[200005];
const double pi=acos(-1);
bool inner(int x1, int y1, int x2, int y2, pair<int, int> x){
	return x.first>=x1&&x.first<=x2&&x.second>=y1&&x.second<=y2;
}
int main(){
	int x1, x2, y1, y2;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d%d", &arr[i].first, &arr[i].second);
	if(x1==x2){
		if(y1>y2)
			swap(y1, y2);
		bool flag=false;
		for(int i=0;i<n;i++)
			if(arr[i].first==x1&&arr[i].second>y1&&arr[i].second<y2)
				flag=true;
		printf("%.15lf\n", (y2-y1)*100.0+(flag?pi*10-20:0));
		return 0;
	}
	if(y1==y2){
		if(x1>x2)
			swap(x1, x2);
		bool flag=false;
		for(int i=0;i<n;i++)
			if(arr[i].second==y1&&arr[i].first>x1&&arr[i].first<x2)
				flag=true;
		printf("%.15lf\n", (x2-x1)*100.0+(flag?pi*10-20:0));
		return 0;
	}
	if(x1>x2){
		swap(x1, x2);
		swap(y1, y2);
	}
	if(y1<y2){
		vector<pair<int, int> > vec;
		for(int i=0;i<n;i++){
			if(inner(x1, y1, x2, y2, arr[i]))
				vec.push_back(arr[i]);
		}
		sort(vec.begin(), vec.end());
		vector<int> lis;
		for(int i=0;i<vec.size();i++){
			auto it=lower_bound(lis.begin(), lis.end(), vec[i].second);
			if(it==lis.end())
				lis.push_back(vec[i].second);
			else
				*it=vec[i].second;
		}
		int len=lis.size();
		if(len==min(y2-y1, x2-x1)+1)
			printf("%.15lf\n", (x2-x1+y2-y1)*100.0+(len-1)*(5*pi-20)+pi*10-20);
		else
			printf("%.15lf\n", (x2-x1+y2-y1)*100.0+len*(5*pi-20));
		return 0;
	}
	vector<pair<int, int> > vec;
	for(int i=0;i<n;i++){
		if(inner(x1, y2, x2, y1, arr[i]))
			vec.push_back({arr[i].first, 1e8-arr[i].second});
	}
	sort(vec.begin(), vec.end());
	vector<int> lis;
	for(int i=0;i<vec.size();i++){
		auto it=lower_bound(lis.begin(), lis.end(), vec[i].second);
		if(it==lis.end())
			lis.push_back(vec[i].second);
		else
			*it=vec[i].second;
	}
	int len=lis.size();
	if(len==min(y1-y2, x2-x1)+1)
		printf("%.15lf\n", (x2-x1+y1-y2)*100.0+(len-1)*(5*pi-20)+pi*10-20);
	else
		printf("%.15lf\n", (x2-x1+y1-y2)*100.0+len*(5*pi-20));
	return 0;
}

