// =====================================================================================
// 
//       Filename:  7662.cpp
//        Created:  2017년 01월 18일 23시 34분 42초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National Uiversity
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<long long, int> > max_q;
priority_queue<pair<long long, int> > min_q;
bool check[1000000];
int main(){
	int Case;
	scanf("%d", &Case);
	while(Case--){
		memset(check, 0, sizeof(check));
		while(!min_q.empty())
			min_q.pop();
		while(!max_q.empty())
			max_q.pop();
		int k;
		scanf("%d", &k);
		for(int i=0;i<k;i++){
			char input[2];
			long long num;
			scanf("%s%lld", input, &num);
			if(input[0]=='I'){
				max_q.push({num, i});
				min_q.push({-num, i});
			}
			else{
				if(num==1){
					while(!max_q.empty()){
						int idx=max_q.top().second;
						max_q.pop();
						if(check[idx]){
							continue;
						}
						check[idx]=true;
						break;
					}
				}
				else{
					while(!min_q.empty()){
						int idx=min_q.top().second;
						min_q.pop();
						if(check[idx]){
							continue;
						}
						check[idx]=true;
						break;
					}
				}
			}	
			while(!max_q.empty()){
				int idx=max_q.top().second;
				if(check[idx]){
					max_q.pop();
					continue;
				}
				break;
			}
			while(!min_q.empty()){
				int idx=min_q.top().second;
				if(check[idx]){
					min_q.pop();
					continue;
				}
				break;
			}
		}
		if(max_q.empty()||min_q.empty())
			printf("EMPTY\n");
		else
			printf("%lld %lld\n", max_q.top().first, -min_q.top().first);
	}
	return 0;
}

