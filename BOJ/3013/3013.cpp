#include <bits/stdc++.h>
using namespace std;
int n,b;
int arr[100005];
int p=1e6;
long long solve(int le,int ri){
	if(le==ri)
		return arr[le]==p;
	int mid=(le+ri)/2;
	long long ret=solve(le,mid)+solve(mid+1,ri);
	map<int,int> mp;
	long long sum=0;
	for(int i=mid;i>=le;i--){
		sum+=arr[i];
		mp[sum]++;
	}
	sum=0;
	for(int i=mid+1;i<=ri;i++){
		sum+=arr[i];
		ret+=mp[p-sum];
	}
	return ret;
}
int main(){
	int base=0;
	scanf("%d%d",&n,&b);
	long long cnt=0;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(x==b)
			x=p;
		else if(x<b)
			x=-1;
		else
			x=1;
		arr[i]=x;
	}
	printf("%lld\n",solve(0,n-1));
	return 0;
}