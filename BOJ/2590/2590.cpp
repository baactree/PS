// =====================================================================================
// 
//       Filename:  2590.cpp
//        Created:  2017년 04월 09일 16시 17분 39초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int cnt[6];
int main(){
	for(int i=0;i<6;i++)
		scanf("%d", &cnt[i]);
	int ans=0;
	ans+=cnt[5];
	for(int i=0;i<cnt[4];i++){
		ans++;
		cnt[0]-=11;
		cnt[0]=max(cnt[0], 0);
	}
	for(int i=0;i<cnt[3];i++){
		ans++;
		if(cnt[1]>=5)
			cnt[1]-=5;
		else{
			int temp=5-cnt[1];
			cnt[1]=0;
			cnt[0]-=temp*4;
			cnt[0]=max(cnt[0], 0);
		}
	}
	ans+=cnt[2]/4;

	cnt[2]%=4;
	if(cnt[2]!=0){
		int temp=4-cnt[2];
		ans++;
		if(temp==1){
			int v=9;
			if(cnt[1]>0){
				cnt[1]--;
				v-=4;
			}
			cnt[0]-=v;
			cnt[0]=max(cnt[0], 0);
		}
		if(temp==2){
			int v=18;
			int t=min(cnt[1], 3);
			v-=4*t;
			cnt[1]-=t;
			cnt[0]-=v;
			cnt[0]=max(cnt[0], 0);
		}
		if(temp==3){
			int v=27;
			int t=min(cnt[1], 5);
			v-=4*t;
			cnt[1]-=t;
			cnt[0]-=v;
			cnt[0]=max(cnt[0], 0);
		}
	}

	ans+=cnt[1]/9;
	cnt[1]%=9;
	if(cnt[1]>0){
		ans++;
		int temp=9-cnt[1];
		cnt[0]-=temp*4;
		cnt[0]=max(cnt[0], 0);
	}	
	ans+=cnt[0]/36;
	cnt[0]%=36;
	ans+=cnt[0]!=0;
	printf("%d\n", ans);
	return 0;
}

