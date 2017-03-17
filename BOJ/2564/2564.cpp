// =====================================================================================
// 
//       Filename:  2564.cpp
//        Created:  2017년 03월 15일 20시 58분 22초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int w, h;
int n;
pair<int, int> arr[100];
pair<int, int> d;
int main(){
	scanf("%d%d", &w, &h);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d", &arr[i].first, &arr[i].second);
	scanf("%d%d", &d.first, &d.second);
	int sum=0;
	if(d.first==1){
		for(int i=0;i<n;i++){
			if(arr[i].first==1){
				sum+=abs(arr[i].second-d.second);
			}
			else if(arr[i].first==2){
				sum+=h+min(arr[i].second+d.second, w-d.second+w-arr[i].second);
			}
			else if(arr[i].first==3){
				sum+=arr[i].second+d.second;
			}
			else{
				sum+=w-d.second+arr[i].second;
			}
		}
	}
	else if(d.first==2){
		for(int i=0;i<n;i++){
			if(arr[i].first==1){
				sum+=h+min(arr[i].second+d.second, w-d.second+w-arr[i].second);
			}
			else if(arr[i].first==2){
				sum+=abs(arr[i].second-d.second);
			}
			else if(arr[i].first==3){
				sum+=d.second+h-arr[i].second;
			}
			else{
				sum+=w-d.second+h-arr[i].second;
			}
		}
	}
	else if(d.first==3){
		for(int i=0;i<n;i++){
			if(arr[i].first==1){
				sum+=arr[i].second+d.second;
			}
			else if(arr[i].first==2){
				sum+=h-d.second+arr[i].second;
			}
			else if(arr[i].first==3){
				sum+=abs(arr[i].second-d.second);
			}
			else{
				sum+=w+min(arr[i].second+d.second, h-d.second+h-arr[i].second);
			}
		}
	}
	else{
		for(int i=0;i<n;i++){
			if(arr[i].first==1){
				sum+=w-arr[i].second+d.second;
			}
			else if(arr[i].first==2){
				sum+=h-d.second+w-arr[i].second;
			}
			else if(arr[i].first==3){
				sum+=w+min(arr[i].second+d.second, h-d.second+h-arr[i].second);
			}
			else{
				sum+=abs(arr[i].second-d.second);
			}
		}
	}
	printf("%d\n", sum);
	return 0;
}

