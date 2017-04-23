// =====================================================================================
// 
//       Filename:  1713.cpp
//        Created:  2017년 04월 23일 21시 48분 41초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
bool on[101];
pair<int, int> cnt[101];
int tk;
int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i=0;i<k;i++){
		int in;
		scanf("%d", &in);
		if(on[in])
			cnt[in].first++;
		else{
			if(tk==n){
				int idx;
				int min_value=0x3f3f3f3f;
				int last_date;
				for(int j=1;j<=100;j++){
					if(!on[j])
						continue;
					if(cnt[j].first<min_value){
						min_value=cnt[j].first;
						idx=j;
						last_date=cnt[j].second;
					}
					else if(cnt[j].first==min_value){
						if(cnt[j].second<last_date){
							last_date=cnt[j].second;
							idx=j;
						}
					}
				}
				on[idx]=false;
				cnt[idx]={0, 0};
				on[in]=true;
				cnt[in].second=i;
				cnt[in].first=1;
			}
			else{
				on[in]=true;
				cnt[in].second=i;
				cnt[in].first=1;
				tk++;
			}
		}
	}
	for(int i=1;i<=100;i++)
		if(on[i])
			printf("%d ", i);
	printf("\n");
	return 0;
}

