#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100005];
int get_idx(int lo,int hi,int x){
	int le,ri,mid,ret;
	le=lo;
	ri=hi-1;
	ret=hi;
	while(le<=ri){
		mid=(le+ri)/2;
		if(arr[mid]&(1<<x)){
			ret=mid;
			ri=mid-1;
		}
		else
			le=mid+1;
	}
	return ret;
}
int calc(int x){
	int lo,hi,ret;
	lo=0;
	hi=n;
	ret=0;
	for(int i=31;i>=0;i--){
		int idx=get_idx(lo,hi,i);
		//[lo,idx), [idx,hi)
		bool flag=false;
		if(x&(1<<i)){
			if(lo==idx){
				flag=true;
				ret+=1<<i;
			}
		}
		else{
			if(hi!=idx){
				flag=true;
				ret+=1<<i;
			}
		}
		if(flag)
			lo=idx;
		else
			hi=idx;
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	sort(arr,arr+n);
	int ans=0;
	for(int i=0;i<n;i++){
		int now=calc(arr[i]);
		ans=max(ans,now^arr[i]);
	}
	printf("%d\n",ans);
	return 0;
}