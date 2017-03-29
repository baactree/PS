// =====================================================================================
// 
//       Filename:  9007.cpp
//        Created:  2017년 03월 29일 19시 08분 32초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[1000], b[1000], c[1000], d[1000];
int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		scanf("%d%d", &k, &n);
		for(int i=0;i<n;i++)
			scanf("%d", &a[i]);
		for(int i=0;i<n;i++)
			scanf("%d", &b[i]);
		for(int i=0;i<n;i++)
			scanf("%d", &c[i]);
		for(int i=0;i<n;i++)
			scanf("%d", &d[i]);
		vector<int> ab;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				ab.push_back(a[i]+b[j]);
		sort(ab.begin(), ab.end());
		int ans=0x3f3f3f3f;
		int diff=0x3f3f3f3f;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				int now=c[i]+d[j];
				int idx=lower_bound(ab.begin(), ab.end(), k-now)-ab.begin();
				if(idx==ab.size()){
					int pick=ab[ab.size()-1];
					if(diff>abs(k-(now+pick))){
						diff=abs(k-(now+pick));
						ans=now+pick;
					}
					else if(diff==abs(k-(now+pick)))
						if(ans>now+pick){
							ans=now+pick;
						}
					continue;
				}
				if(idx!=0){
					int pick=ab[idx-1];
					if(diff>abs(k-(now+pick))){
						diff=abs(k-(now+pick));
						ans=now+pick;
					}
					else if(diff==abs(k-(now+pick)))
						if(ans>now+pick){
							ans=now+pick;
						}
				}
				int pick=ab[idx];
				if(diff>abs(k-(now+pick))){
					diff=abs(k-(now+pick));
					ans=now+pick;
				}
				else if(diff==abs(k-(now+pick)))
					if(ans>now+pick){
						ans=now+pick;
					}
			}
		printf("%d\n", ans);
	}
	return 0;
}

