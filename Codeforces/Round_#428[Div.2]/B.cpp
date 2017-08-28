// =====================================================================================
// 
//       Filename:  B.cpp
//        Created:  2017년 08월 14일 15시 33분 56초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[100];
int main(){
	scanf("%d%d", &n, &k);
	priority_queue<int> pq;
	for(int i=0;i<k;i++){
		scanf("%d", &arr[i]);
		pq.push(arr[i]);
	}
	int cnt[5]={0, };
	cnt[2]=n*2;
	cnt[4]=n;
	while(!pq.empty()){
		int now=pq.top();
		pq.pop();
		if(now>4){
			int t=min(cnt[4], now/4);
			cnt[4]-=t;
			now=now-4*t;
			t=min(cnt[2], now/2);
			cnt[2]-=t;
			now=now-2*t;
			if(now)
				pq.push(now);
		}
		else if(now==4){
			if(cnt[4])
				cnt[4]--;
			else if(cnt[2]){
				cnt[2]--;
				pq.push(2);
			}
			else
				return !printf("NO\n");
		}
		else if(now==3){
			if(cnt[4])
				cnt[4]--;
			else if(cnt[2]){
				cnt[2]--;
				pq.push(1);
			}
			else
				return !printf("NO\n");
		}
		else if(now==2){
			if(cnt[4]){
				cnt[4]--;
				cnt[1]++;
			}
			else if(cnt[2])
				cnt[2]--;
			else
				return !printf("NO\n");
		}
		else if(now==1){
			if(cnt[4]){
				cnt[4]--;
				cnt[2]++;
			}
			else if(cnt[2])
				cnt[2]--;
			else if(cnt[1])
				cnt[1]--;
			else
				return !printf("NO\n");
		}
	}
	printf("YES\n");
	return 0;
}

