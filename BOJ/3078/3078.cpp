#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char input[25];
int arr[300005];
int cnt[25];
int n,k;
int main(){
	ll ans=0;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%s",input);
		int len=strlen(input);
		arr[i]=len;
		ans+=cnt[len];
		cnt[len]++;
		if(i>=k)
			cnt[arr[i-k]]--;
	}
	printf("%lld\n",ans);
	return 0;
}