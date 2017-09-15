// =====================================================================================
// 
//       Filename:  6884.cpp
//        Created:  2017년 09월 15일 20시 36분 19초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int prime[3125005];
inline void paint(int x){
	int a=x/32;
	int b=x%32;
	prime[a]|=(1<<b);
}
inline bool find(int x){
	int a=x/32;
	int b=x%32;
	return prime[a]&(1<<b);
}
int arr[10005];
int main(){
	paint(0);
	paint(1);
	for(int i=2;i<=1e8;i++){
		if(!find(i)){
			for(long long j=(long long)i*i;j<=1e8;j+=i)
				paint(j);
		}
	}
	int testcase;
	scanf("%d", &testcase);
	while(testcase--){
		int n;
		scanf("%d", &n);
		for(int i=0;i<n;i++)
			scanf("%d", &arr[i]);
		vector<int> vec;
		int ans=0x3f3f3f3f;
		int idx=-1;
		for(int i=0;i<n;i++){
			for(int j=0;j<vec.size();j++){
				vec[j]+=arr[i];
				if(!find(vec[j])){
					if(ans>(int)vec.size()-j+1){
						ans=(int)vec.size()-j+1;
						idx=i-ans+1;
					}
				}
			}
			vec.push_back(arr[i]);
		}
		if(ans==0x3f3f3f3f)
			printf("This sequence is anti-primed.\n");
		else{
			printf("Shortest primed subsequence is length %d:", ans);
			for(int i=idx;i<idx+ans;i++)
				printf(" %d", arr[i]);
			printf("\n");
		}

	}
	return 0;
}

