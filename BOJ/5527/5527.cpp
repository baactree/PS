#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100005];
int le[100005];
int ri[100005];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(int i=0;i<n;i++){
		int st=i;
		int now=arr[i++];
		while(i<n&&arr[i-1]!=arr[i])
			i++;
		ri[st]=i-st;
		i--;
	}
	for(int i=n-1;i>=0;i--){
		int st=i;
		int now=arr[i--];
		while(i>=0&&arr[i+1]!=arr[i])
			i--;
		le[st]=st-i;
		i++;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(ri[i]){
			int len=ri[i];
			int now=ri[i];
			if(i>0)
				now+=le[i-1];
			if(i+len<n)
				now+=ri[i+len];
			ans=max(ans,now);
		}
	}
	printf("%d\n",ans);
	return 0;
}