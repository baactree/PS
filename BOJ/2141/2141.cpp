// =====================================================================================
// 
//       Filename:  2141.cpp
//        Created:  2017년 05월 08일 16시 36분 54초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> arr[100000];
long long sum=0;
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d%d", &arr[i].first, &arr[i].second);
		sum+=arr[i].second;
	}
	sort(arr, arr+n);
	int ans=0;
	long long nsum=0;
	for(int i=0;i<n;i++){
		nsum+=arr[i].second;
		if(nsum*2>=sum){
			ans=arr[i].first;
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}

