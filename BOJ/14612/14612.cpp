// =====================================================================================
// 
//       Filename:  14612.cpp
//        Created:  2017년 06월 26일 16시 59분 54초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, m;
bool trip[101];
vector<pair<int, int> > arr;
int main(){
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++){
		string t;
		int a, b;
		cin>>t;
		if(t=="sort"){
			sort(arr.begin(), arr.end());
		}
		else if(t=="complete"){
			scanf("%d", &a);
			for(int i=0;i<arr.size();i++){
				if(arr[i].second==a){
					arr.erase(arr.begin()+i);
					i--;
				}
			}
		}
		else{
			scanf("%d%d", &a, &b);
			arr.push_back({b, a});
		}
		for(int i=0;i<arr.size();i++){
			printf("%d ", arr[i].second);
		}
		if(arr.empty())
			printf("sleep");
		printf("\n");
	}
	return 0;
}

