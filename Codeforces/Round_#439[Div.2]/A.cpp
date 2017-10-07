#include <bits/stdc++.h>
using namespace std;
int n;
int x[2005],y[2005];
int cnt[20000005];
int main(){
	scanf("%d",&n);
	int now=0;
	for(int i=0;i<n;i++){
		scanf("%d",&x[i]);
		cnt[x[i]]++;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&y[i]);
		cnt[y[i]]++;
	}
	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if(cnt[(x[i]^y[j])])
				ans++;
		}
	printf("%s\n",ans%2==0?"Karen":"Koyomi");
	return 0;
}