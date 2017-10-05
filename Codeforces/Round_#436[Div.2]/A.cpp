#include <bits/stdc++.h>
using namespace std;
int n;
int cnt[105];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		cnt[x]++;
	}
	for(int i=1;i<=100;i++)
		for(int j=i+1;j<=100;j++){
			if(cnt[i]&&cnt[j]&&cnt[i]==cnt[j]&&cnt[i]+cnt[j]==n)
				return !printf("YES\n%d %d\n",i,j);
		}
	printf("NO\n");
	return 0;
}