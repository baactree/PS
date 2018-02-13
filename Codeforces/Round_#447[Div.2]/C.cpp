#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1005];
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int g=arr[0];
	for(int i=1;i<n;i++)
		g=gcd(g,arr[i]);
	if(g!=arr[0])
		return !printf("-1\n");
	printf("%d\n",n*2);
	for(int i=0;i<n;i++)
		printf("%d %d ",arr[i],arr[0]);
	printf("\n");
	return 0;
}