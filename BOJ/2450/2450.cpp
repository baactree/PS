// =====================================================================================
// 
//       Filename:  2450.cpp
//        Created:  2017년 08월 03일 01시 46분 58초
//       Compiler:  g++ -O2 -std=c++14
//         Author:  baactree ,  bsj0206@naver.com
//        Company:  Chonnam National University
// 
// =====================================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100000];
int s[100000];
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d", &x);
		arr[i]=x-1;
	}
	vector<int> perm({0, 1, 2});
	int ans=0x3f3f3f3f;
	do{
		for(int i=0;i<n;i++)
			s[i]=perm[arr[i]];
		sort(s, s+n);
		int cnt[3][3]={0, };
		for(int i=0;i<n;i++){
			if(s[i]==perm[arr[i]])
				continue;
			if(s[i]==0&&perm[arr[i]]==1)
				cnt[0][1]++;
			if(s[i]==0&&perm[arr[i]]==2)
				cnt[0][2]++;
			if(s[i]==1&&perm[arr[i]]==0)
				cnt[1][0]++;
			if(s[i]==1&&perm[arr[i]]==2)
				cnt[1][2]++;
			if(s[i]==2&&perm[arr[i]]==0)
				cnt[2][0]++;
			if(s[i]==2&&perm[arr[i]]==1)
				cnt[2][1]++;
		}
		int temp=0;
		for(int i=0;i<3;i++)
			for(int j=i+1;j<3;j++){
				int x=min(cnt[i][j], cnt[j][i]);
				if(x==0)
					continue;
				cnt[i][j]-=x;
				cnt[j][i]-=x;
				temp+=x;
			}
		int k=0;
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				k=max(k, cnt[i][j]);
		temp+=k*2;
		ans=min(ans, temp);
	}while(next_permutation(perm.begin(), perm.end()));
	printf("%d\n", ans);
	return 0;
}

