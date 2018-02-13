#include <bits/stdc++.h>
using namespace std;
int n;
int cnt[100005];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		cnt[x]++;
	}
	for(int i=n;i>=0;i--)
		if(cnt[i]==i)
			return !printf("%d\n",i);
	printf("-1\n");
	return 0;
}