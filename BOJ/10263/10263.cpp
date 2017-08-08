// =====================================================================================
// 
//       Filename:  10263.cpp
//        Created:  2017년 08월 08일 12시 36분 09초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> vec;
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d", &x);
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end());
	int ans=0;
	int cnt=0;
	while(true){
		int idx=upper_bound(vec.begin(), vec.end(), cnt)-vec.begin();
		if(idx==vec.size())
			break;
		int a=vec.size()-idx;
		int b=vec.back()-cnt;
		if(a<b){
			vec.pop_back();
			ans++;
		}
		else{
			ans++;
			cnt++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

