#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005],b[100005];
int main(){
	scanf("%d",&n);
	long long sum=0;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	sort(b,b+n);
	if(b[n-1]+b[n-2]>=sum)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}