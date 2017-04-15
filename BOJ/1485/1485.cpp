// =====================================================================================
// 
//       Filename:  1485.cpp
//        Created:  2017년 04월 15일 11시 34분 56초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;

pair<int, int> p[4];
bool possi(){
	for(int i=1;i<4;i++){
		p[i].first-=p[0].first;
		p[i].second-=p[0].second;
	}
	for(int i=1;i<4;i++)
		for(int j=1;j<4;j++){
			for(int k=1;k<4;k++){
				if(i==j||j==k||k==i)
					continue;
				//i와 j가 직교함
				if(p[i].first*p[j].first+p[i].second*p[j].second==0){
					//k가 i+j임
					if(p[i].first+p[j].first==p[k].first&&p[i].second+p[j].second==p[k].second){
						if(p[i].first*p[i].first+p[i].second*p[i].second==p[j].first*p[j].first+p[j].second*p[j].second)
							return true;
					}
				}
			}
		}
	return false;
	
}
int main(){
	int TestCase;
	scanf("%d", &TestCase);
	while(TestCase--){
		for(int i=0;i<4;i++)
			scanf("%d%d", &p[i].first, &p[i].second);
		printf("%d\n", possi());
	}
	return 0;
}

