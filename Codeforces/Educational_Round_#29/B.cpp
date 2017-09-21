// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 09월 22일 00시 10분 51초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n*2;i++)
		scanf("%d", &arr[i]);
	int ans=0x3f3f3f3f;
	n*=2;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			vector<int> vec;
			for(int k=0;k<n;k++){
				if(k==i||k==j)
					continue;
				vec.push_back(arr[k]);
			}
			sort(vec.begin(), vec.end());
			int sum=0;
			for(int k=0;k<vec.size();k+=2){
				sum+=vec[k+1]-vec[k];
			}
			ans=min(ans, sum);
		}
	}
	printf("%d\n", ans);
	return 0;
}

