// =====================================================================================
// 
//       Filename:  5430.cpp
//        Created:  2017년 03월 02일 14시 27분 47초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
deque<int> arr;
int n;
int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		arr.clear();
		string order;
		cin>>order;
		scanf("%d\n", &n);
		char temp;
		scanf("%c", &temp);
		for(int i=0;i<n;i++){
			int in;
			scanf("%d,", &in);
			arr.push_back(in);
		}
		scanf("%c", &temp);

		bool flag=false;
		
		for(int i=0;i<order.size();i++){
			if(order[i]=='R')
				flag=1-flag;
			else{
				if(arr.size()==0){
					printf("error\n");
					goto next;
				}
				if(flag){
					arr.pop_back();
				}
				else
					arr.pop_front();
			}
		}

		if(flag)
			reverse(arr.begin(), arr.end());
		printf("[");
		for(int i=0;i<arr.size();i++)
			printf("%s%d", i==0?"":",", arr[i]);
		printf("]\n");
		next:;
	}
	return 0;
}

