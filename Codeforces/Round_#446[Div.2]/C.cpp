#include <bits/stdc++.h>
using namespace std;
int n;
int arr[2005];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
const int inf=0x3f3f3f3f;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int g=arr[0];
	for(int i=1;i<n;i++)
		g=gcd(g,arr[i]);
	if(g!=1)
		return !printf("-1\n");
	bool flag=false;
	int st=-1;
	for(int i=0;i<n;i++){
		if(arr[i]==1){
			flag=true;
			st=i;
			break;
		}
	}
	if(flag){
		int ans=st;
		for(int i=st+1;i<n;i++){
			if(arr[i]==1)
				continue;
			ans++;
		}
		return !printf("%d\n",ans);
	}
	int len=inf;
	for(int i=0;i<n;i++){
		int k=arr[i];
		int now=0;
		bool flag=false;
		for(int j=i+1;j<n;j++){
			now++;
			k=gcd(k,arr[j]);
			if(k==1){
				flag=true;
				break;
			}
		}
		if(flag)
			len=min(len,now);
	}
	printf("%d\n",n-1+len);
	return 0;
}