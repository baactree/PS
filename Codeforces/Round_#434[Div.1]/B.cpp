// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 09월 17일 22시 25분 35초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[70000];
string ans[70000];
bool chk[70000]={0, };
int d[11];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	d[1]=1;
	for(int i=2;i<=10;i++)
		d[i]=d[i-1]*10;
	vector<pair<pair<int, int>, int> > vec;
	for(int len=1;len<=9;len++){
		for(int i=0;i<n;i++){
			for(int j=0;j+len<=9;j++){
				int now=(arr[i]%d[10-j])/d[10-(j+len)];	
				vec.push_back({{len, now}, i});
			}
		}
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	vector<bool> s(vec.size(), 0);
	for(int i=1;i<vec.size();i++){
		if(vec[i].first==vec[i-1].first){
			s[i]=s[i-1]=true;
		}
	}
	for(int i=0;i<vec.size();i++){
		if(!s[i]&&!chk[vec[i].second]){
			chk[vec[i].second]=true;
			string now=to_string(vec[i].first.second);
			ans[vec[i].second]=string(vec[i].first.first-now.size(), '0')+now;
		}
	}
	for(int i=0;i<n;i++)
		cout<<ans[i]<<'\n';
	return 0;
}

