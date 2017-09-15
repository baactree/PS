// =====================================================================================
// 
//       Filename:  1253.cpp
//        Created:  2017년 09월 15일 16시 45분 42초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[2000];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	sort(arr, arr+n);
	int cnt=0;
	for(int i=0;i<n;i++){
		vector<int> vec;
		for(int j=0;j<n;j++)
			if(j==i)
				continue;
			else
				vec.push_back(arr[j]);
		bool flag=false;
		for(int j=0;j<vec.size();j++){
			auto it=lower_bound(vec.begin(), vec.end(), arr[i]-vec[j]);
			if(it-vec.begin()==j)
				it++;
			if(it!=vec.end()&&*it==(arr[i]-vec[j]))
				flag=true;
		}
		if(flag){
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}

